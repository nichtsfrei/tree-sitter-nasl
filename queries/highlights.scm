"break" @keyword
"continue" @keyword
"else" @keyword
"for" @keyword
"if" @keyword
"return" @keyword
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
(type_identifier) @type

((identifier) @constant
 (#match? @constant "^[A-Z][A-Z\\d_]*$"))

(identifier) @variable

(comment) @comment
