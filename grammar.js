const PREC = {
  PAREN_DECLARATOR: -10,
  ASSIGNMENT: -1,
  CONDITIONAL: -2,
  LOGICAL_OR: 1,
  LOGICAL_AND: 2,
  INCLUSIVE_OR: 3,
  EXCLUSIVE_OR: 4,
  BITWISE_AND: 5,
  EQUAL: 6,
  RELATIONAL: 7,
  SIZEOF: 8,
  SHIFT: 9,
  ADD: 10,
  MULTIPLY: 11,
  CAST: 12,
  UNARY: 13,
  CALL: 14,
  FIELD: 15,
  SUBSCRIPT: 16
};

module.exports = grammar({
  name: 'nasl',
  externals: $ => [
    $._unescaped_double_string_fragment,
    $._unescaped_single_string_fragment,
    $._unescaped_double_string_fragment_no_quoted_end,
    $._unescaped_single_string_fragment_no_quoted_end,
  ],

  extras: $ => [
    /\s|\\\r?\n/,
    $.comment,
  ],

  inline: $ => [
    $._statement,
    $._top_level_item,
    $._type_identifier,
    $._field_identifier,
    $._statement_identifier,
    $._non_case_statement,
    $._assignment_left_expression,
  ],

  conflicts: $ => [
    [$._type_specifier, $._declarator],
    [$._type_specifier, $._declarator, $.macro_type_specifier],
    [$._type_specifier, $._expression],
    [$._type_specifier, $._expression, $.macro_type_specifier],
    [$._type_specifier, $.macro_type_specifier],
    [$._declaration_modifiers, $.attributed_non_case_statement],
  ],

  word: $ => $.identifier,

  rules: {
    source_file: $ => repeat($._top_level_item),

    _top_level_item: $ => choice(
      $.function_definition,
      $.declaration,
      $._statement,
      $._empty_declaration,
    ),

    // Main Grammar

    function_definition: $ => seq(
      'function',
      field('declarator', $._declarator),
      field('body', $.compound_statement)
    ),

    declaration: $ => seq(
      $._declaration_specifiers,
      commaSep1(field('declarator', choice(
        $._declarator,
        $.init_declarator
      ))),
      ';'
    ),

    _declaration_modifiers: $ => choice(
      $.attribute_specifier,
      $.attribute_declaration,
      $.ms_declspec_modifier
    ),

    _declaration_specifiers: $ => seq(
      repeat($._declaration_modifiers),
      field('type', $._type_specifier),
      repeat($._declaration_modifiers),
    ),

    attribute_specifier: $ => seq(
      '__attribute__',
      '(',
      $.argument_list,
      ')'
    ),

    attribute: $ => seq(
      optional(seq(field('prefix', $.identifier), '::')),
      field('name', $.identifier),
      optional($.argument_list)
    ),

    attribute_declaration: $ => seq(
      '[[',
      commaSep1($.attribute),
      ']]'
    ),

    ms_declspec_modifier: $ => seq(
      '__declspec',
      '(',
      $.identifier,
      ')',
    ),

    ms_based_modifier: $ => seq(
      '__based',
      $.argument_list,
    ),

    ms_call_modifier: $ => choice(
      '__cdecl',
      '__clrcall',
      '__stdcall',
      '__fastcall',
      '__thiscall',
      '__vectorcall'
    ),

    ms_restrict_modifier: $ => '__restrict',

    ms_unsigned_ptr_modifier: $ => '__uptr',

    ms_signed_ptr_modifier: $ => '__sptr',

    ms_unaligned_ptr_modifier: $ => choice('_unaligned', '__unaligned'),

    ms_pointer_modifier: $ => choice(
      $.ms_unaligned_ptr_modifier,
      $.ms_restrict_modifier,
      $.ms_unsigned_ptr_modifier,
      $.ms_signed_ptr_modifier,
    ),

    declaration_list: $ => seq(
      '{',
      repeat($._top_level_item),
      '}'
    ),

    _declarator: $ => choice(
      $.attributed_declarator,
      $.pointer_declarator,
      $.function_declarator,
      $.array_declarator,
      $.parenthesized_declarator,
      $.identifier
    ),

    _field_declarator: $ => choice(
      alias($.attributed_field_declarator, $.attributed_declarator),
      alias($.pointer_field_declarator, $.pointer_declarator),
      alias($.function_field_declarator, $.function_declarator),
      alias($.array_field_declarator, $.array_declarator),
      alias($.parenthesized_field_declarator, $.parenthesized_declarator),
      $._field_identifier
    ),

    _type_declarator: $ => choice(
      alias($.attributed_type_declarator, $.attributed_declarator),
      alias($.pointer_type_declarator, $.pointer_declarator),
      alias($.function_type_declarator, $.function_declarator),
      alias($.array_type_declarator, $.array_declarator),
      alias($.parenthesized_type_declarator, $.parenthesized_declarator),
      $._type_identifier
    ),

    _abstract_declarator: $ => choice(
      $.abstract_pointer_declarator,
      $.abstract_function_declarator,
      $.abstract_array_declarator,
      $.abstract_parenthesized_declarator,
    ),

    parenthesized_declarator: $ => prec.dynamic(PREC.PAREN_DECLARATOR, seq(
      '(',
      $._declarator,
      ')'
    )),
    parenthesized_field_declarator: $ => prec.dynamic(PREC.PAREN_DECLARATOR, seq(
      '(',
      $._field_declarator,
      ')'
    )),
    parenthesized_type_declarator: $ => prec.dynamic(PREC.PAREN_DECLARATOR, seq(
      '(',
      $._type_declarator,
      ')'
    )),
    abstract_parenthesized_declarator: $ => prec(1, seq(
      '(',
      $._abstract_declarator,
      ')'
    )),


    attributed_declarator: $ => prec.right(seq(
      $._declarator,
      repeat1($.attribute_declaration),
    )),
    attributed_field_declarator: $ => prec.right(seq(
      $._field_declarator,
      repeat1($.attribute_declaration),
    )),
    attributed_type_declarator: $ => prec.right(seq(
      $._type_declarator,
      repeat1($.attribute_declaration),
    )),

    pointer_declarator: $ => prec.dynamic(1, prec.right(seq(
      optional($.ms_based_modifier),
      '*',
      repeat($.ms_pointer_modifier),
      field('declarator', $._declarator)
    ))),
    pointer_field_declarator: $ => prec.dynamic(1, prec.right(seq(
      optional($.ms_based_modifier),
      '*',
      repeat($.ms_pointer_modifier),
      field('declarator', $._field_declarator)
    ))),
    pointer_type_declarator: $ => prec.dynamic(1, prec.right(seq(
      optional($.ms_based_modifier),
      '*',
      repeat($.ms_pointer_modifier),
      field('declarator', $._type_declarator)
    ))),
    abstract_pointer_declarator: $ => prec.dynamic(1, prec.right(seq('*',
      field('declarator', optional($._abstract_declarator))
    ))),

    function_declarator: $ => prec(1,
      seq(
        field('declarator', $._declarator),
        field('parameters', $.parameter_list),
        repeat($.attribute_specifier),
      )),
    function_field_declarator: $ => prec(1, seq(
      field('declarator', $._field_declarator),
      field('parameters', $.parameter_list)
    )),
    function_type_declarator: $ => prec(1, seq(
      field('declarator', $._type_declarator),
      field('parameters', $.parameter_list)
    )),
    abstract_function_declarator: $ => prec(1, seq(
      field('declarator', optional($._abstract_declarator)),
      field('parameters', $.parameter_list)
    )),

    array_declarator: $ => prec(1, seq(
      field('declarator', $._declarator),
      '[',
      field('size', optional(choice($._expression, '*'))),
      ']'
    )),
    array_field_declarator: $ => prec(1, seq(
      field('declarator', $._field_declarator),
      '[',
      field('size', optional(choice($._expression, '*'))),
      ']'
    )),
    array_type_declarator: $ => prec(1, seq(
      field('declarator', $._type_declarator),
      '[',
      field('size', optional(choice($._expression, '*'))),
      ']'
    )),
    abstract_array_declarator: $ => prec(1, seq(
      field('declarator', optional($._abstract_declarator)),
      '[',
      field('size', optional(choice($._expression, '*'))),
      ']'
    )),

    init_declarator: $ => seq(
      field('declarator', $._declarator),
      '=',
      field('value', choice($.initializer_list, $._expression))
    ),

    compound_statement: $ => seq(
      '{',
      repeat($._top_level_item),
      '}'
    ),

    _type_specifier: $ => choice(
      $.macro_type_specifier,
      $._type_identifier
    ),


    field_declaration_list: $ => seq(
      '{',
      repeat($._field_declaration_list_item),
      '}'
    ),

    _field_declaration_list_item: $ => choice(
      $.field_declaration,
    ),

    field_declaration: $ => seq(
      $._declaration_specifiers,
      commaSep(field('declarator', $._field_declarator)),
      ';'
    ),


    parameter_list: $ => seq(
      '(',
      commaSep($.identifier),
      ')'
    ),


    // Statements

    attributed_non_case_statement: $ => seq(
      repeat1($.attribute_declaration),
      $._non_case_statement
    ),

    _statement: $ => choice(
      $._non_case_statement
    ),

    _non_case_statement: $ => choice(
      $.compound_statement,
      $.expression_statement,
      $.if_statement,
      $.repeat_statement,
      $.while_statement,
      $.foreach_statement,
      $.for_statement,
      $.return_statement,
      $.break_statement,
      $.continue_statement,
    ),

    expression_statement: $ => seq(
      optional(choice(
        $._expression,
        $.comma_expression
      )),
      ';'
    ),

    if_statement: $ => prec.right(seq(
      'if',
      field('condition', $.parenthesized_expression),
      field('consequence', $._statement),
      optional(seq(
        'else',
        field('alternative', $._statement)
      ))
    )),


    while_statement: $ => seq(
      'while',
      field('condition', $.parenthesized_expression),
      field('body', $._statement)
    ),

    repeat_statement: $ => seq(
      'repeat',
      field('body', $._statement),
      'until',
      field('condition', $.parenthesized_expression),
      ';'
    ),
    foreach_statement: $ => seq(
      'foreach',
      field('element', $.identifier),
      field('selection', $.argument_list),
      field('body', $._statement),
    ),

    for_statement: $ => seq(
      'for',
      '(',
      choice(
        field('initializer', $.declaration),
        seq(field('initializer', optional(choice($._expression, $.comma_expression))), ';')
      ),
      field('condition', optional($._expression)), ';',
      field('update', optional(choice($._expression, $.comma_expression))),
      ')',
      field('body', $._statement),
    ),

    return_statement: $ => seq(
      'return',
      optional(choice($._expression, $.comma_expression)),
      ';'
    ),

    break_statement: $ => seq(
      'break', ';'
    ),

    continue_statement: $ => seq(
      'continue', ';'
    ),


    // Expressions

    _expression: $ => choice(
      $.assignment_expression,
      $.binary_expression,
      $.unary_expression,
      $.update_expression,
      $.pointer_expression,
      $.subscript_expression,
      $.call_expression,
      $.field_expression,
      $.compound_literal_expression,
      $.identifier,
      $.number_literal,
      $.string_literal,
      $.true,
      $.false,
      $.null,
      $.concatenated_string,
      $.parenthesized_expression
    ),

    comma_expression: $ => seq(
      field('left', $._expression),
      ',',
      field('right', choice($._expression, $.comma_expression))
    ),


    _assignment_left_expression: $ => choice(
      $.identifier,
      $.call_expression,
      $.field_expression,
      $.pointer_expression,
      $.subscript_expression,
      $.parenthesized_expression
    ),

    assignment_expression: $ => prec.right(PREC.ASSIGNMENT, seq(
      field('left', $._assignment_left_expression),
      field('operator', choice(
        '=',
        '*=',
        '/=',
        '%=',
        '+=',
        '-=',
        '<<=',
        '>>=',
        '&=',
        '^=',
        '|='
      )),
      field('right', $._expression)
    )),

    pointer_expression: $ => prec.left(PREC.CAST, seq(
      field('operator', choice('*', '&')),
      field('argument', $._expression)
    )),

    unary_expression: $ => prec.left(PREC.UNARY, seq(
      field('operator', choice('!', '~', '-', '+')),
      field('argument', $._expression)
    )),

    binary_expression: $ => {
      const table = [
        ['+', PREC.ADD],
        ['-', PREC.ADD],
        ['*', PREC.MULTIPLY],
        ['/', PREC.MULTIPLY],
        ['%', PREC.MULTIPLY],
        ['||', PREC.LOGICAL_OR],
        ['&&', PREC.LOGICAL_AND],
        ['|', PREC.INCLUSIVE_OR],
        ['^', PREC.EXCLUSIVE_OR],
        ['&', PREC.BITWISE_AND],
        ['==', PREC.EQUAL],
        ['!=', PREC.EQUAL],
        ['!~', PREC.EQUAL],
        ['>', PREC.RELATIONAL],
        ['>=', PREC.RELATIONAL],
        ['<=', PREC.RELATIONAL],
        ['<', PREC.RELATIONAL],
        ['><', PREC.RELATIONAL],
        ['>!<', PREC.RELATIONAL],
        ['<<', PREC.SHIFT],
        ['>>', PREC.SHIFT],
      ];

      return choice(...table.map(([operator, precedence]) => {
        return prec.left(precedence, seq(
          field('left', $._expression),
          field('operator', operator),
          field('right', $._expression)
        ))
      }));
    },

    update_expression: $ => {
      const argument = field('argument', $._expression);
      const operator = field('operator', choice('--', '++'));
      return prec.right(PREC.UNARY, choice(
        seq(operator, argument),
        seq(argument, operator),
      ));
    },

    type_descriptor: $ => seq(
      field('type', $._type_specifier),
      field('declarator', optional($._abstract_declarator))
    ),

    subscript_expression: $ => prec(PREC.SUBSCRIPT, seq(
      field('argument', $._expression),
      '[',
      field('index', $._expression),
      ']'
    )),

    call_expression: $ => prec(PREC.CALL, seq(
      field('function', $._expression),
      field('arguments', $.argument_list)
    )),
    named_argument: $ => seq($.identifier, ":", $._expression),

    argument_list: $ => seq('(', commaSep(choice($._expression, $.named_argument)), ')'),

    field_expression: $ => seq(
      prec(PREC.FIELD, seq(
        field('argument', $._expression),
        field('operator', choice('.', '->'))
      )),
      field('field', $._field_identifier)
    ),

    compound_literal_expression: $ => seq(
      '(',
      field('type', $.type_descriptor),
      ')',
      field('value', $.initializer_list)
    ),

    parenthesized_expression: $ => seq(
      '(',
      choice($._expression, $.comma_expression),
      ')'
    ),

    initializer_list: $ => seq(
      '{',
      commaSep(choice(
        $.initializer_pair,
        $._expression,
        $.initializer_list
      )),
      optional(','),
      '}'
    ),

    initializer_pair: $ => seq(
      field('designator', repeat1(choice($.subscript_designator, $.field_designator))),
      '=',
      field('value', choice($._expression, $.initializer_list))
    ),

    subscript_designator: $ => seq('[', $._expression, ']'),

    field_designator: $ => seq('.', $._field_identifier),

    number_literal: $ => {
      const separator = "'";
      const hex = /[0-9a-fA-F]/;
      const decimal = /[0-9]/;
      const hexDigits = seq(repeat1(hex), repeat(seq(separator, repeat1(hex))));
      const decimalDigits = seq(repeat1(decimal), repeat(seq(separator, repeat1(decimal))));
      return token(seq(
        optional(/[-\+]/),
        optional(choice('0x', '0b')),
        choice(
          seq(
            choice(
              decimalDigits,
              seq('0b', decimalDigits),
              seq('0x', hexDigits)
            ),
            optional(seq('.', optional(hexDigits)))
          ),
          seq('.', decimalDigits)
        ),
        optional(seq(
          /[eEpP]/,
          optional(seq(
            optional(/[-\+]/),
            hexDigits
          ))
        )),
        repeat(choice('u', 'l', 'U', 'L', 'f', 'F'))
      ))
    },

    concatenated_string: $ => seq(
      $.string_literal,
      repeat1($.string_literal)
    ),


    // nasl supports "hjdahk\hkjdhak\" as well as "hj\"...going forward"
    // I have no clue how to support both
    string_literal: $ => choice(
      seq(
        '"',
        prec.right(choice(
          alias($._unescaped_double_string_fragment, $.string_fragment),
          alias($._unescaped_double_string_fragment_no_quoted_end, $.string_fragment),
        )),
        '"'
      ),
      seq(
        "'",
        prec.right(choice(
          alias($._unescaped_single_string_fragment, $.string_fragment),
          alias($._unescaped_single_string_fragment_no_quoted_end, $.string_fragment),
        )),
        "'"
      )
    ),

    true: $ => token(choice('TRUE', 'true')),
    false: $ => token(choice('FALSE', 'false')),
    null: $ => 'NULL',

    identifier: $ => /[a-zA-Z_]\w*/,

    _type_identifier: $ => alias($.identifier, $.type_identifier),
    _field_identifier: $ => alias($.identifier, $.field_identifier),
    _statement_identifier: $ => alias($.identifier, $.statement_identifier),

    _empty_declaration: $ => seq(
      $._type_specifier,
      ';'
    ),

    macro_type_specifier: $ => prec.dynamic(-1, seq(
      field('name', $.identifier),
      '(',
      field('type', $.type_descriptor),
      ')'
    )),

    // http://stackoverflow.com/questions/13014947/regex-to-match-a-c-style-multiline-comment/36328890#36328890
    comment: $ => token(choice(
      seq('//', /(\\(.|\r?\n)|[^\\\n])*/),
      seq('#', /(\\(.|\r?\n)|[^\\\n])*/),
      seq(
        '/*',
        /[^*]*\*+([^/*][^*]*\*+)*/,
        '/'
      )
    )),
  },

  supertypes: $ => [
    $._expression,
    $._statement,
    $._type_specifier,
    $._declarator,
    $._field_declarator,
    $._type_declarator,
    $._abstract_declarator,
  ]
});

function commaSep(rule) {
  return optional(commaSep1(rule))
}

function commaSep1(rule) {
  return seq(rule, repeat(seq(',', rule)))
}
