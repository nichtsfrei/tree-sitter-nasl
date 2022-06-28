module.exports = grammar({
  name: 'nasl',

  rules: {
    source_file: $ => repeat($._definition),

    _definition: $ => choice(
      $.comment,
      $.func_def,
      $.func_impl,
      $.if_statement,
      $.func_call,
      $.assignment,
      $.return,
    ),
    comment: $ => token(choice(
      seq('#', /.*/),
      seq('//', /.*/),
      seq(
        '/*',
        /[^*]*\*+([^/*][^*]*\*+)*/,
        '/'
      )
    )),
    // TODO define corectly
    if_statement: $ => seq(
      'if',
      $.arguments,
      choice(
        $.block,
        $._statement,
      ),
    ),
    _statement: $ => choice(
      $.func_call,
      $.assignment,
    ),
    func_def: $ => seq(
      'function',
      $.identifier,
      $.arguments,
      ";",
    ),
    func_impl: $ => seq(
      'function',
      $.identifier,
      $.arguments,
      $.block,
    ),
    // TODO remove duplicate to function
    func_call: $ => seq(
      $.identifier,
      $.arguments,
      ";",
    ),
    assignment: $ => seq(
      /[a-z_]+/,
      '=',
      $._expression,
      ";"
    ),
    arguments: $ => seq(
      '(',
      optional(commaSep(choice($._expression, $.named_identifier))),
      ')',
    ),

    block: $ => seq(
      '{',
      repeat($._definition),
      '}'
    ),
    return: $ => seq(
      'return',
      $._expression,
      ';',
    ),
    function: $ => seq(
      $.identifier,
      $.arguments,
    ),
    _expression: $ => choice(
      $.identifier,
      $.number,
      $.string,
      $.function,
    ),


    // Here we tolerate unescaped newlines in double-quoted and
    // single-quoted string literals.
    // This is legal in typescript as jsx/tsx attribute values (as of
    // 2020), and perhaps will be valid in javascript as well in the
    // future.
    //
    string: $ => choice(
      seq(
        '"',
        repeat(choice(
          alias($.unescaped_double_string_fragment, $.string_fragment),
          $.escape_sequence
        )),
        '"'
      ),
      seq(
        "'",
        repeat(choice(
          alias($.unescaped_single_string_fragment, $.string_fragment),
          $.escape_sequence
        )),
        "'"
      )
    ),

    // Workaround to https://github.com/tree-sitter/tree-sitter/issues/1156
    // We give names to the token() constructs containing a regexp
    // so as to obtain a node in the CST.
    //
    unescaped_double_string_fragment: $ =>
      token.immediate(prec(1, /[^"\\]+/)),

    // same here
    unescaped_single_string_fragment: $ =>
      token.immediate(prec(1, /[^'\\]+/)),

    escape_sequence: $ => token.immediate(seq(
      '\\',
      choice(
        /[^xu0-7]/,
        /[0-7]{1,3}/,
        /x[0-9a-fA-F]{2}/,
        /u[0-9a-fA-F]{4}/,
        /u{[0-9a-fA-F]+}/
      )
    )),

    identifier: $ => choice(
      /[a-z_]+/,
      /[A-Z_]+/,
      /[\w]+/,
    ),
    named_identifier: $ => seq(alias($.identifier, $.key), ":", alias($._expression, $.value),),

    number: $ => /\d+/

  }
});

function commaSep1(rule) {
  return seq(rule, repeat(seq(',', rule)));
}

function commaSep(rule) {
  return optional(commaSep1(rule));
}
