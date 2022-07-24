"break" @keyword
"const" @keyword
"continue" @keyword
"else" @keyword
"extern" @keyword
"for" @keyword
"if" @keyword
"return" @keyword
"typedef" @keyword
"union" @keyword
"volatile" @keyword
"while" @keyword
"foreach" @keyword
"repeat" @keyword
"until" @keyword

"--" @operator
"-" @operator
"-=" @operator
"->" @operator
"=" @operator
"!=" @operator
"*" @operator
"&" @operator
"&&" @operator
"+" @operator
"++" @operator
"+=" @operator
"<" @operator
"==" @operator
">" @operator
"||" @operator
"><" @operator
">!<" @operator

"." @delimiter
";" @delimiter

(string_literal) @string

(null) @constant
(number_literal) @number

(call_expression
  function: (identifier) @function)
(call_expression
  function: (field_expression
    field: (field_identifier) @function))
(function_declarator
  declarator: (identifier) @function)

(field_identifier) @property
(statement_identifier) @label
(type_identifier) @type
(primitive_type) @type

((identifier) @constant
 (#match? @constant "^[A-Z][A-Z\\d_]*$"))

(identifier) @variable

(comment) @comment
