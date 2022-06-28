#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 13
#define STATE_COUNT 51
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 42
#define ALIAS_COUNT 2
#define TOKEN_COUNT 22
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 4
#define PRODUCTION_ID_COUNT 2

enum {
  sym_comment = 1,
  anon_sym_if = 2,
  anon_sym_function = 3,
  anon_sym_SEMI = 4,
  aux_sym_assignment_token1 = 5,
  anon_sym_EQ = 6,
  anon_sym_LPAREN = 7,
  anon_sym_COMMA = 8,
  anon_sym_RPAREN = 9,
  anon_sym_LBRACE = 10,
  anon_sym_RBRACE = 11,
  anon_sym_return = 12,
  anon_sym_DQUOTE = 13,
  anon_sym_SQUOTE = 14,
  sym_unescaped_double_string_fragment = 15,
  sym_unescaped_single_string_fragment = 16,
  sym_escape_sequence = 17,
  aux_sym_identifier_token1 = 18,
  aux_sym_identifier_token2 = 19,
  anon_sym_COLON = 20,
  sym_number = 21,
  sym_source_file = 22,
  sym__definition = 23,
  sym_if_statement = 24,
  sym__statement = 25,
  sym_func_def = 26,
  sym_func_impl = 27,
  sym_func_call = 28,
  sym_assignment = 29,
  sym_arguments = 30,
  sym_block = 31,
  sym_return = 32,
  sym_function = 33,
  sym__expression = 34,
  sym_string = 35,
  sym_identifier = 36,
  sym_named_identifier = 37,
  aux_sym_source_file_repeat1 = 38,
  aux_sym_arguments_repeat1 = 39,
  aux_sym_string_repeat1 = 40,
  aux_sym_string_repeat2 = 41,
  alias_sym_key = 42,
  alias_sym_value = 43,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_comment] = "comment",
  [anon_sym_if] = "if",
  [anon_sym_function] = "function",
  [anon_sym_SEMI] = ";",
  [aux_sym_assignment_token1] = "assignment_token1",
  [anon_sym_EQ] = "=",
  [anon_sym_LPAREN] = "(",
  [anon_sym_COMMA] = ",",
  [anon_sym_RPAREN] = ")",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [anon_sym_return] = "return",
  [anon_sym_DQUOTE] = "\"",
  [anon_sym_SQUOTE] = "'",
  [sym_unescaped_double_string_fragment] = "string_fragment",
  [sym_unescaped_single_string_fragment] = "string_fragment",
  [sym_escape_sequence] = "escape_sequence",
  [aux_sym_identifier_token1] = "identifier_token1",
  [aux_sym_identifier_token2] = "identifier_token2",
  [anon_sym_COLON] = ":",
  [sym_number] = "number",
  [sym_source_file] = "source_file",
  [sym__definition] = "_definition",
  [sym_if_statement] = "if_statement",
  [sym__statement] = "_statement",
  [sym_func_def] = "func_def",
  [sym_func_impl] = "func_impl",
  [sym_func_call] = "func_call",
  [sym_assignment] = "assignment",
  [sym_arguments] = "arguments",
  [sym_block] = "block",
  [sym_return] = "return",
  [sym_function] = "function",
  [sym__expression] = "_expression",
  [sym_string] = "string",
  [sym_identifier] = "identifier",
  [sym_named_identifier] = "named_identifier",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_arguments_repeat1] = "arguments_repeat1",
  [aux_sym_string_repeat1] = "string_repeat1",
  [aux_sym_string_repeat2] = "string_repeat2",
  [alias_sym_key] = "key",
  [alias_sym_value] = "value",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_comment] = sym_comment,
  [anon_sym_if] = anon_sym_if,
  [anon_sym_function] = anon_sym_function,
  [anon_sym_SEMI] = anon_sym_SEMI,
  [aux_sym_assignment_token1] = aux_sym_assignment_token1,
  [anon_sym_EQ] = anon_sym_EQ,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [anon_sym_return] = anon_sym_return,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [anon_sym_SQUOTE] = anon_sym_SQUOTE,
  [sym_unescaped_double_string_fragment] = sym_unescaped_double_string_fragment,
  [sym_unescaped_single_string_fragment] = sym_unescaped_double_string_fragment,
  [sym_escape_sequence] = sym_escape_sequence,
  [aux_sym_identifier_token1] = aux_sym_identifier_token1,
  [aux_sym_identifier_token2] = aux_sym_identifier_token2,
  [anon_sym_COLON] = anon_sym_COLON,
  [sym_number] = sym_number,
  [sym_source_file] = sym_source_file,
  [sym__definition] = sym__definition,
  [sym_if_statement] = sym_if_statement,
  [sym__statement] = sym__statement,
  [sym_func_def] = sym_func_def,
  [sym_func_impl] = sym_func_impl,
  [sym_func_call] = sym_func_call,
  [sym_assignment] = sym_assignment,
  [sym_arguments] = sym_arguments,
  [sym_block] = sym_block,
  [sym_return] = sym_return,
  [sym_function] = sym_function,
  [sym__expression] = sym__expression,
  [sym_string] = sym_string,
  [sym_identifier] = sym_identifier,
  [sym_named_identifier] = sym_named_identifier,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_arguments_repeat1] = aux_sym_arguments_repeat1,
  [aux_sym_string_repeat1] = aux_sym_string_repeat1,
  [aux_sym_string_repeat2] = aux_sym_string_repeat2,
  [alias_sym_key] = alias_sym_key,
  [alias_sym_value] = alias_sym_value,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym_comment] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_if] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_function] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SEMI] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_assignment_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_return] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DQUOTE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SQUOTE] = {
    .visible = true,
    .named = false,
  },
  [sym_unescaped_double_string_fragment] = {
    .visible = true,
    .named = true,
  },
  [sym_unescaped_single_string_fragment] = {
    .visible = true,
    .named = true,
  },
  [sym_escape_sequence] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_identifier_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_identifier_token2] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [sym_number] = {
    .visible = true,
    .named = true,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym__definition] = {
    .visible = false,
    .named = true,
  },
  [sym_if_statement] = {
    .visible = true,
    .named = true,
  },
  [sym__statement] = {
    .visible = false,
    .named = true,
  },
  [sym_func_def] = {
    .visible = true,
    .named = true,
  },
  [sym_func_impl] = {
    .visible = true,
    .named = true,
  },
  [sym_func_call] = {
    .visible = true,
    .named = true,
  },
  [sym_assignment] = {
    .visible = true,
    .named = true,
  },
  [sym_arguments] = {
    .visible = true,
    .named = true,
  },
  [sym_block] = {
    .visible = true,
    .named = true,
  },
  [sym_return] = {
    .visible = true,
    .named = true,
  },
  [sym_function] = {
    .visible = true,
    .named = true,
  },
  [sym__expression] = {
    .visible = false,
    .named = true,
  },
  [sym_string] = {
    .visible = true,
    .named = true,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym_named_identifier] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_arguments_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_string_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_string_repeat2] = {
    .visible = false,
    .named = false,
  },
  [alias_sym_key] = {
    .visible = true,
    .named = true,
  },
  [alias_sym_value] = {
    .visible = true,
    .named = true,
  },
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
  [1] = {
    [0] = alias_sym_key,
    [2] = alias_sym_value,
  },
};

static const uint16_t ts_non_terminal_alias_map[] = {
  sym__expression, 2,
    sym__expression,
    alias_sym_value,
  sym_identifier, 2,
    sym_identifier,
    alias_sym_key,
  0,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(15);
      if (lookahead == '"') ADVANCE(43);
      if (lookahead == '#') ADVANCE(17);
      if (lookahead == '\'') ADVANCE(44);
      if (lookahead == '(') ADVANCE(37);
      if (lookahead == ')') ADVANCE(39);
      if (lookahead == ',') ADVANCE(38);
      if (lookahead == '/') ADVANCE(4);
      if (lookahead == ':') ADVANCE(55);
      if (lookahead == ';') ADVANCE(20);
      if (lookahead == '=') ADVANCE(36);
      if (lookahead == '\\') ADVANCE(7);
      if (lookahead == '_') ADVANCE(21);
      if (lookahead == 'f') ADVANCE(33);
      if (lookahead == 'i') ADVANCE(24);
      if (lookahead == 'r') ADVANCE(23);
      if (lookahead == '{') ADVANCE(40);
      if (lookahead == '}') ADVANCE(41);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(14)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(53);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(35);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(52);
      END_STATE();
    case 1:
      if (lookahead == '"') ADVANCE(43);
      if (lookahead == '\'') ADVANCE(44);
      if (lookahead == ')') ADVANCE(39);
      if (lookahead == ',') ADVANCE(38);
      if (lookahead == ';') ADVANCE(20);
      if (lookahead == '_') ADVANCE(21);
      if (lookahead == '{') ADVANCE(40);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(1)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(53);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(52);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(35);
      END_STATE();
    case 2:
      if (lookahead == '"') ADVANCE(43);
      if (lookahead == '\\') ADVANCE(7);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(45);
      if (lookahead != 0) ADVANCE(46);
      END_STATE();
    case 3:
      if (lookahead == '\'') ADVANCE(44);
      if (lookahead == '\\') ADVANCE(7);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(47);
      if (lookahead != 0) ADVANCE(48);
      END_STATE();
    case 4:
      if (lookahead == '*') ADVANCE(6);
      if (lookahead == '/') ADVANCE(17);
      END_STATE();
    case 5:
      if (lookahead == '*') ADVANCE(5);
      if (lookahead == '/') ADVANCE(16);
      if (lookahead != 0) ADVANCE(6);
      END_STATE();
    case 6:
      if (lookahead == '*') ADVANCE(5);
      if (lookahead != 0) ADVANCE(6);
      END_STATE();
    case 7:
      if (lookahead == 'u') ADVANCE(8);
      if (lookahead == 'x') ADVANCE(13);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(51);
      if (lookahead != 0) ADVANCE(49);
      END_STATE();
    case 8:
      if (lookahead == '{') ADVANCE(12);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(10);
      END_STATE();
    case 9:
      if (lookahead == '}') ADVANCE(49);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(9);
      END_STATE();
    case 10:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(13);
      END_STATE();
    case 11:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(49);
      END_STATE();
    case 12:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(9);
      END_STATE();
    case 13:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(11);
      END_STATE();
    case 14:
      if (eof) ADVANCE(15);
      if (lookahead == '"') ADVANCE(43);
      if (lookahead == '#') ADVANCE(17);
      if (lookahead == '\'') ADVANCE(44);
      if (lookahead == '(') ADVANCE(37);
      if (lookahead == ')') ADVANCE(39);
      if (lookahead == ',') ADVANCE(38);
      if (lookahead == '/') ADVANCE(4);
      if (lookahead == ':') ADVANCE(55);
      if (lookahead == ';') ADVANCE(20);
      if (lookahead == '=') ADVANCE(36);
      if (lookahead == '_') ADVANCE(21);
      if (lookahead == 'f') ADVANCE(33);
      if (lookahead == 'i') ADVANCE(24);
      if (lookahead == 'r') ADVANCE(23);
      if (lookahead == '{') ADVANCE(40);
      if (lookahead == '}') ADVANCE(41);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(14)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(53);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(35);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(52);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(sym_comment);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(17);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(anon_sym_if);
      if (lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(35);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(54);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(anon_sym_function);
      if (lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(35);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(54);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(aux_sym_assignment_token1);
      if (lookahead == '_') ADVANCE(21);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(54);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(52);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(35);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(aux_sym_assignment_token1);
      if (lookahead == 'c') ADVANCE(31);
      if (lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(35);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(54);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(aux_sym_assignment_token1);
      if (lookahead == 'e') ADVANCE(32);
      if (lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(35);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(54);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(aux_sym_assignment_token1);
      if (lookahead == 'f') ADVANCE(18);
      if (lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(35);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(54);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(aux_sym_assignment_token1);
      if (lookahead == 'i') ADVANCE(29);
      if (lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(35);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(54);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(aux_sym_assignment_token1);
      if (lookahead == 'n') ADVANCE(22);
      if (lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(35);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(54);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(aux_sym_assignment_token1);
      if (lookahead == 'n') ADVANCE(42);
      if (lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(35);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(54);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(aux_sym_assignment_token1);
      if (lookahead == 'n') ADVANCE(19);
      if (lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(35);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(54);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(aux_sym_assignment_token1);
      if (lookahead == 'o') ADVANCE(28);
      if (lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(35);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(54);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(aux_sym_assignment_token1);
      if (lookahead == 'r') ADVANCE(27);
      if (lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(35);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(54);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(aux_sym_assignment_token1);
      if (lookahead == 't') ADVANCE(25);
      if (lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(35);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(54);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(aux_sym_assignment_token1);
      if (lookahead == 't') ADVANCE(34);
      if (lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(35);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(54);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(aux_sym_assignment_token1);
      if (lookahead == 'u') ADVANCE(26);
      if (lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(35);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(54);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(aux_sym_assignment_token1);
      if (lookahead == 'u') ADVANCE(30);
      if (lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(35);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(54);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(aux_sym_assignment_token1);
      if (lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(35);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(54);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(anon_sym_return);
      if (lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(35);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(54);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(sym_unescaped_double_string_fragment);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(45);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(46);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(sym_unescaped_double_string_fragment);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(46);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(sym_unescaped_single_string_fragment);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(47);
      if (lookahead != 0 &&
          lookahead != '\'' &&
          lookahead != '\\') ADVANCE(48);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(sym_unescaped_single_string_fragment);
      if (lookahead != 0 &&
          lookahead != '\'' &&
          lookahead != '\\') ADVANCE(48);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(sym_escape_sequence);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(sym_escape_sequence);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(49);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(sym_escape_sequence);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(50);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(aux_sym_identifier_token1);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(52);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(54);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(aux_sym_identifier_token2);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(53);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(54);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(aux_sym_identifier_token2);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(54);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 1},
  [7] = {.lex_state = 1},
  [8] = {.lex_state = 1},
  [9] = {.lex_state = 1},
  [10] = {.lex_state = 1},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 0},
  [13] = {.lex_state = 1},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 1},
  [21] = {.lex_state = 1},
  [22] = {.lex_state = 1},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 0},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 3},
  [27] = {.lex_state = 3},
  [28] = {.lex_state = 2},
  [29] = {.lex_state = 3},
  [30] = {.lex_state = 2},
  [31] = {.lex_state = 2},
  [32] = {.lex_state = 1},
  [33] = {.lex_state = 0},
  [34] = {.lex_state = 0},
  [35] = {.lex_state = 0},
  [36] = {.lex_state = 0},
  [37] = {.lex_state = 0},
  [38] = {.lex_state = 0},
  [39] = {.lex_state = 0},
  [40] = {.lex_state = 0},
  [41] = {.lex_state = 0},
  [42] = {.lex_state = 0},
  [43] = {.lex_state = 0},
  [44] = {.lex_state = 0},
  [45] = {.lex_state = 0},
  [46] = {.lex_state = 0},
  [47] = {.lex_state = 0},
  [48] = {.lex_state = 0},
  [49] = {.lex_state = 0},
  [50] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_comment] = ACTIONS(1),
    [anon_sym_if] = ACTIONS(1),
    [anon_sym_function] = ACTIONS(1),
    [anon_sym_SEMI] = ACTIONS(1),
    [aux_sym_assignment_token1] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [anon_sym_return] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [anon_sym_SQUOTE] = ACTIONS(1),
    [sym_escape_sequence] = ACTIONS(1),
    [aux_sym_identifier_token1] = ACTIONS(1),
    [aux_sym_identifier_token2] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [sym_number] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(47),
    [sym__definition] = STATE(5),
    [sym_if_statement] = STATE(5),
    [sym_func_def] = STATE(5),
    [sym_func_impl] = STATE(5),
    [sym_func_call] = STATE(5),
    [sym_assignment] = STATE(5),
    [sym_return] = STATE(5),
    [sym_identifier] = STATE(44),
    [aux_sym_source_file_repeat1] = STATE(5),
    [ts_builtin_sym_end] = ACTIONS(3),
    [sym_comment] = ACTIONS(5),
    [anon_sym_if] = ACTIONS(7),
    [anon_sym_function] = ACTIONS(9),
    [aux_sym_assignment_token1] = ACTIONS(11),
    [anon_sym_return] = ACTIONS(13),
    [aux_sym_identifier_token1] = ACTIONS(15),
    [aux_sym_identifier_token2] = ACTIONS(15),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 9,
    ACTIONS(19), 1,
      sym_comment,
    ACTIONS(22), 1,
      anon_sym_if,
    ACTIONS(25), 1,
      anon_sym_function,
    ACTIONS(28), 1,
      aux_sym_assignment_token1,
    ACTIONS(31), 1,
      anon_sym_return,
    STATE(44), 1,
      sym_identifier,
    ACTIONS(17), 2,
      ts_builtin_sym_end,
      anon_sym_RBRACE,
    ACTIONS(34), 2,
      aux_sym_identifier_token1,
      aux_sym_identifier_token2,
    STATE(2), 8,
      sym__definition,
      sym_if_statement,
      sym_func_def,
      sym_func_impl,
      sym_func_call,
      sym_assignment,
      sym_return,
      aux_sym_source_file_repeat1,
  [37] = 9,
    ACTIONS(7), 1,
      anon_sym_if,
    ACTIONS(9), 1,
      anon_sym_function,
    ACTIONS(11), 1,
      aux_sym_assignment_token1,
    ACTIONS(13), 1,
      anon_sym_return,
    ACTIONS(37), 1,
      sym_comment,
    ACTIONS(39), 1,
      anon_sym_RBRACE,
    STATE(44), 1,
      sym_identifier,
    ACTIONS(15), 2,
      aux_sym_identifier_token1,
      aux_sym_identifier_token2,
    STATE(2), 8,
      sym__definition,
      sym_if_statement,
      sym_func_def,
      sym_func_impl,
      sym_func_call,
      sym_assignment,
      sym_return,
      aux_sym_source_file_repeat1,
  [73] = 9,
    ACTIONS(7), 1,
      anon_sym_if,
    ACTIONS(9), 1,
      anon_sym_function,
    ACTIONS(11), 1,
      aux_sym_assignment_token1,
    ACTIONS(13), 1,
      anon_sym_return,
    ACTIONS(41), 1,
      sym_comment,
    ACTIONS(43), 1,
      anon_sym_RBRACE,
    STATE(44), 1,
      sym_identifier,
    ACTIONS(15), 2,
      aux_sym_identifier_token1,
      aux_sym_identifier_token2,
    STATE(3), 8,
      sym__definition,
      sym_if_statement,
      sym_func_def,
      sym_func_impl,
      sym_func_call,
      sym_assignment,
      sym_return,
      aux_sym_source_file_repeat1,
  [109] = 9,
    ACTIONS(7), 1,
      anon_sym_if,
    ACTIONS(9), 1,
      anon_sym_function,
    ACTIONS(11), 1,
      aux_sym_assignment_token1,
    ACTIONS(13), 1,
      anon_sym_return,
    ACTIONS(37), 1,
      sym_comment,
    ACTIONS(45), 1,
      ts_builtin_sym_end,
    STATE(44), 1,
      sym_identifier,
    ACTIONS(15), 2,
      aux_sym_identifier_token1,
      aux_sym_identifier_token2,
    STATE(2), 8,
      sym__definition,
      sym_if_statement,
      sym_func_def,
      sym_func_impl,
      sym_func_call,
      sym_assignment,
      sym_return,
      aux_sym_source_file_repeat1,
  [145] = 8,
    ACTIONS(47), 1,
      anon_sym_RPAREN,
    ACTIONS(49), 1,
      anon_sym_DQUOTE,
    ACTIONS(51), 1,
      anon_sym_SQUOTE,
    ACTIONS(53), 1,
      sym_number,
    STATE(24), 1,
      sym_identifier,
    STATE(34), 2,
      sym__expression,
      sym_named_identifier,
    STATE(36), 2,
      sym_function,
      sym_string,
    ACTIONS(15), 3,
      aux_sym_assignment_token1,
      aux_sym_identifier_token1,
      aux_sym_identifier_token2,
  [174] = 7,
    ACTIONS(49), 1,
      anon_sym_DQUOTE,
    ACTIONS(51), 1,
      anon_sym_SQUOTE,
    ACTIONS(53), 1,
      sym_number,
    STATE(24), 1,
      sym_identifier,
    STATE(36), 2,
      sym_function,
      sym_string,
    STATE(45), 2,
      sym__expression,
      sym_named_identifier,
    ACTIONS(15), 3,
      aux_sym_assignment_token1,
      aux_sym_identifier_token1,
      aux_sym_identifier_token2,
  [200] = 7,
    ACTIONS(49), 1,
      anon_sym_DQUOTE,
    ACTIONS(51), 1,
      anon_sym_SQUOTE,
    ACTIONS(53), 1,
      sym_number,
    STATE(23), 1,
      sym_identifier,
    STATE(50), 1,
      sym__expression,
    STATE(36), 2,
      sym_function,
      sym_string,
    ACTIONS(15), 3,
      aux_sym_assignment_token1,
      aux_sym_identifier_token1,
      aux_sym_identifier_token2,
  [225] = 7,
    ACTIONS(49), 1,
      anon_sym_DQUOTE,
    ACTIONS(51), 1,
      anon_sym_SQUOTE,
    ACTIONS(53), 1,
      sym_number,
    STATE(23), 1,
      sym_identifier,
    STATE(46), 1,
      sym__expression,
    STATE(36), 2,
      sym_function,
      sym_string,
    ACTIONS(15), 3,
      aux_sym_assignment_token1,
      aux_sym_identifier_token1,
      aux_sym_identifier_token2,
  [250] = 7,
    ACTIONS(49), 1,
      anon_sym_DQUOTE,
    ACTIONS(51), 1,
      anon_sym_SQUOTE,
    ACTIONS(53), 1,
      sym_number,
    STATE(23), 1,
      sym_identifier,
    STATE(49), 1,
      sym__expression,
    STATE(36), 2,
      sym_function,
      sym_string,
    ACTIONS(15), 3,
      aux_sym_assignment_token1,
      aux_sym_identifier_token1,
      aux_sym_identifier_token2,
  [275] = 2,
    ACTIONS(55), 3,
      ts_builtin_sym_end,
      sym_comment,
      anon_sym_RBRACE,
    ACTIONS(57), 6,
      anon_sym_if,
      anon_sym_function,
      aux_sym_assignment_token1,
      anon_sym_return,
      aux_sym_identifier_token1,
      aux_sym_identifier_token2,
  [289] = 2,
    ACTIONS(59), 3,
      ts_builtin_sym_end,
      sym_comment,
      anon_sym_RBRACE,
    ACTIONS(61), 6,
      anon_sym_if,
      anon_sym_function,
      aux_sym_assignment_token1,
      anon_sym_return,
      aux_sym_identifier_token1,
      aux_sym_identifier_token2,
  [303] = 5,
    ACTIONS(11), 1,
      aux_sym_assignment_token1,
    ACTIONS(63), 1,
      anon_sym_LBRACE,
    STATE(44), 1,
      sym_identifier,
    ACTIONS(15), 2,
      aux_sym_identifier_token1,
      aux_sym_identifier_token2,
    STATE(11), 4,
      sym__statement,
      sym_func_call,
      sym_assignment,
      sym_block,
  [323] = 2,
    ACTIONS(65), 3,
      ts_builtin_sym_end,
      sym_comment,
      anon_sym_RBRACE,
    ACTIONS(67), 6,
      anon_sym_if,
      anon_sym_function,
      aux_sym_assignment_token1,
      anon_sym_return,
      aux_sym_identifier_token1,
      aux_sym_identifier_token2,
  [337] = 2,
    ACTIONS(69), 3,
      ts_builtin_sym_end,
      sym_comment,
      anon_sym_RBRACE,
    ACTIONS(71), 6,
      anon_sym_if,
      anon_sym_function,
      aux_sym_assignment_token1,
      anon_sym_return,
      aux_sym_identifier_token1,
      aux_sym_identifier_token2,
  [351] = 2,
    ACTIONS(73), 3,
      ts_builtin_sym_end,
      sym_comment,
      anon_sym_RBRACE,
    ACTIONS(75), 6,
      anon_sym_if,
      anon_sym_function,
      aux_sym_assignment_token1,
      anon_sym_return,
      aux_sym_identifier_token1,
      aux_sym_identifier_token2,
  [365] = 2,
    ACTIONS(77), 3,
      ts_builtin_sym_end,
      sym_comment,
      anon_sym_RBRACE,
    ACTIONS(79), 6,
      anon_sym_if,
      anon_sym_function,
      aux_sym_assignment_token1,
      anon_sym_return,
      aux_sym_identifier_token1,
      aux_sym_identifier_token2,
  [379] = 2,
    ACTIONS(81), 3,
      ts_builtin_sym_end,
      sym_comment,
      anon_sym_RBRACE,
    ACTIONS(83), 6,
      anon_sym_if,
      anon_sym_function,
      aux_sym_assignment_token1,
      anon_sym_return,
      aux_sym_identifier_token1,
      aux_sym_identifier_token2,
  [393] = 2,
    ACTIONS(85), 3,
      ts_builtin_sym_end,
      sym_comment,
      anon_sym_RBRACE,
    ACTIONS(87), 6,
      anon_sym_if,
      anon_sym_function,
      aux_sym_assignment_token1,
      anon_sym_return,
      aux_sym_identifier_token1,
      aux_sym_identifier_token2,
  [407] = 2,
    ACTIONS(91), 3,
      aux_sym_assignment_token1,
      aux_sym_identifier_token1,
      aux_sym_identifier_token2,
    ACTIONS(89), 4,
      anon_sym_SEMI,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
  [419] = 2,
    ACTIONS(95), 3,
      aux_sym_assignment_token1,
      aux_sym_identifier_token1,
      aux_sym_identifier_token2,
    ACTIONS(93), 4,
      anon_sym_SEMI,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
  [431] = 2,
    ACTIONS(99), 3,
      aux_sym_assignment_token1,
      aux_sym_identifier_token1,
      aux_sym_identifier_token2,
    ACTIONS(97), 4,
      anon_sym_SEMI,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
  [443] = 3,
    ACTIONS(103), 1,
      anon_sym_LPAREN,
    STATE(35), 1,
      sym_arguments,
    ACTIONS(101), 3,
      anon_sym_SEMI,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [455] = 4,
    ACTIONS(103), 1,
      anon_sym_LPAREN,
    ACTIONS(105), 1,
      anon_sym_COLON,
    STATE(35), 1,
      sym_arguments,
    ACTIONS(101), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [469] = 1,
    ACTIONS(107), 5,
      anon_sym_SEMI,
      anon_sym_LPAREN,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_COLON,
  [477] = 3,
    ACTIONS(109), 1,
      anon_sym_SQUOTE,
    STATE(27), 1,
      aux_sym_string_repeat2,
    ACTIONS(111), 2,
      sym_unescaped_single_string_fragment,
      sym_escape_sequence,
  [488] = 3,
    ACTIONS(113), 1,
      anon_sym_SQUOTE,
    STATE(27), 1,
      aux_sym_string_repeat2,
    ACTIONS(115), 2,
      sym_unescaped_single_string_fragment,
      sym_escape_sequence,
  [499] = 3,
    ACTIONS(118), 1,
      anon_sym_DQUOTE,
    STATE(30), 1,
      aux_sym_string_repeat1,
    ACTIONS(120), 2,
      sym_unescaped_double_string_fragment,
      sym_escape_sequence,
  [510] = 3,
    ACTIONS(118), 1,
      anon_sym_SQUOTE,
    STATE(26), 1,
      aux_sym_string_repeat2,
    ACTIONS(122), 2,
      sym_unescaped_single_string_fragment,
      sym_escape_sequence,
  [521] = 3,
    ACTIONS(109), 1,
      anon_sym_DQUOTE,
    STATE(31), 1,
      aux_sym_string_repeat1,
    ACTIONS(124), 2,
      sym_unescaped_double_string_fragment,
      sym_escape_sequence,
  [532] = 3,
    ACTIONS(126), 1,
      anon_sym_DQUOTE,
    STATE(31), 1,
      aux_sym_string_repeat1,
    ACTIONS(128), 2,
      sym_unescaped_double_string_fragment,
      sym_escape_sequence,
  [543] = 2,
    STATE(41), 1,
      sym_identifier,
    ACTIONS(15), 3,
      aux_sym_assignment_token1,
      aux_sym_identifier_token1,
      aux_sym_identifier_token2,
  [552] = 3,
    ACTIONS(131), 1,
      anon_sym_COMMA,
    ACTIONS(133), 1,
      anon_sym_RPAREN,
    STATE(40), 1,
      aux_sym_arguments_repeat1,
  [562] = 3,
    ACTIONS(131), 1,
      anon_sym_COMMA,
    ACTIONS(135), 1,
      anon_sym_RPAREN,
    STATE(33), 1,
      aux_sym_arguments_repeat1,
  [572] = 1,
    ACTIONS(137), 3,
      anon_sym_SEMI,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [578] = 1,
    ACTIONS(101), 3,
      anon_sym_SEMI,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [584] = 1,
    ACTIONS(139), 3,
      anon_sym_SEMI,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [590] = 3,
    ACTIONS(63), 1,
      anon_sym_LBRACE,
    ACTIONS(141), 1,
      anon_sym_SEMI,
    STATE(16), 1,
      sym_block,
  [600] = 1,
    ACTIONS(143), 3,
      anon_sym_SEMI,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [606] = 3,
    ACTIONS(145), 1,
      anon_sym_COMMA,
    ACTIONS(148), 1,
      anon_sym_RPAREN,
    STATE(40), 1,
      aux_sym_arguments_repeat1,
  [616] = 2,
    ACTIONS(103), 1,
      anon_sym_LPAREN,
    STATE(38), 1,
      sym_arguments,
  [623] = 2,
    ACTIONS(103), 1,
      anon_sym_LPAREN,
    STATE(13), 1,
      sym_arguments,
  [630] = 2,
    ACTIONS(107), 1,
      anon_sym_LPAREN,
    ACTIONS(150), 1,
      anon_sym_EQ,
  [637] = 2,
    ACTIONS(103), 1,
      anon_sym_LPAREN,
    STATE(48), 1,
      sym_arguments,
  [644] = 1,
    ACTIONS(148), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [649] = 1,
    ACTIONS(152), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [654] = 1,
    ACTIONS(154), 1,
      ts_builtin_sym_end,
  [658] = 1,
    ACTIONS(156), 1,
      anon_sym_SEMI,
  [662] = 1,
    ACTIONS(158), 1,
      anon_sym_SEMI,
  [666] = 1,
    ACTIONS(160), 1,
      anon_sym_SEMI,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 37,
  [SMALL_STATE(4)] = 73,
  [SMALL_STATE(5)] = 109,
  [SMALL_STATE(6)] = 145,
  [SMALL_STATE(7)] = 174,
  [SMALL_STATE(8)] = 200,
  [SMALL_STATE(9)] = 225,
  [SMALL_STATE(10)] = 250,
  [SMALL_STATE(11)] = 275,
  [SMALL_STATE(12)] = 289,
  [SMALL_STATE(13)] = 303,
  [SMALL_STATE(14)] = 323,
  [SMALL_STATE(15)] = 337,
  [SMALL_STATE(16)] = 351,
  [SMALL_STATE(17)] = 365,
  [SMALL_STATE(18)] = 379,
  [SMALL_STATE(19)] = 393,
  [SMALL_STATE(20)] = 407,
  [SMALL_STATE(21)] = 419,
  [SMALL_STATE(22)] = 431,
  [SMALL_STATE(23)] = 443,
  [SMALL_STATE(24)] = 455,
  [SMALL_STATE(25)] = 469,
  [SMALL_STATE(26)] = 477,
  [SMALL_STATE(27)] = 488,
  [SMALL_STATE(28)] = 499,
  [SMALL_STATE(29)] = 510,
  [SMALL_STATE(30)] = 521,
  [SMALL_STATE(31)] = 532,
  [SMALL_STATE(32)] = 543,
  [SMALL_STATE(33)] = 552,
  [SMALL_STATE(34)] = 562,
  [SMALL_STATE(35)] = 572,
  [SMALL_STATE(36)] = 578,
  [SMALL_STATE(37)] = 584,
  [SMALL_STATE(38)] = 590,
  [SMALL_STATE(39)] = 600,
  [SMALL_STATE(40)] = 606,
  [SMALL_STATE(41)] = 616,
  [SMALL_STATE(42)] = 623,
  [SMALL_STATE(43)] = 630,
  [SMALL_STATE(44)] = 637,
  [SMALL_STATE(45)] = 644,
  [SMALL_STATE(46)] = 649,
  [SMALL_STATE(47)] = 654,
  [SMALL_STATE(48)] = 658,
  [SMALL_STATE(49)] = 662,
  [SMALL_STATE(50)] = 666,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(42),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(32),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(43),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(10),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(25),
  [17] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [19] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(2),
  [22] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(42),
  [25] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(32),
  [28] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(43),
  [31] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(10),
  [34] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(25),
  [37] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [39] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [41] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [43] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [45] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [47] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [49] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [51] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [53] = {.entry = {.count = 1, .reusable = false}}, SHIFT(36),
  [55] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_if_statement, 3),
  [57] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_if_statement, 3),
  [59] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_return, 3),
  [61] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_return, 3),
  [63] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [65] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block, 3),
  [67] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block, 3),
  [69] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_assignment, 4),
  [71] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_assignment, 4),
  [73] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_func_impl, 4),
  [75] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_func_impl, 4),
  [77] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_func_def, 4),
  [79] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_func_def, 4),
  [81] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block, 2),
  [83] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block, 2),
  [85] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_func_call, 3),
  [87] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_func_call, 3),
  [89] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arguments, 4),
  [91] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_arguments, 4),
  [93] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arguments, 2),
  [95] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_arguments, 2),
  [97] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arguments, 3),
  [99] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_arguments, 3),
  [101] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__expression, 1),
  [103] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [105] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [107] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_identifier, 1),
  [109] = {.entry = {.count = 1, .reusable = false}}, SHIFT(37),
  [111] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [113] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_string_repeat2, 2),
  [115] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_string_repeat2, 2), SHIFT_REPEAT(27),
  [118] = {.entry = {.count = 1, .reusable = false}}, SHIFT(39),
  [120] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [122] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [124] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [126] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_string_repeat1, 2),
  [128] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_string_repeat1, 2), SHIFT_REPEAT(31),
  [131] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [133] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [135] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [137] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function, 2),
  [139] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string, 3),
  [141] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [143] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string, 2),
  [145] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_arguments_repeat1, 2), SHIFT_REPEAT(7),
  [148] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_arguments_repeat1, 2),
  [150] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [152] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_named_identifier, 3, .production_id = 1),
  [154] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [156] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [158] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [160] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_nasl(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
