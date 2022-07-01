#include <tree_sitter/parser.h>
#include <stdio.h>
#include <wctype.h>
enum TokenType {
  DOUBLE_FRAGMENT,
  SINGLE_FRAGMENT,
  DOUBLE_FRAGMENT_NO_QUOTED_END,
  SINGLE_FRAGMENT_NO_QUOTED_END,
};

void *tree_sitter_nasl_external_scanner_create() { return NULL; }
void tree_sitter_nasl_external_scanner_destroy(void *p) {}
void tree_sitter_nasl_external_scanner_reset(void *p) {}
unsigned tree_sitter_nasl_external_scanner_serialize(void *p, char *buffer) {
  return 0;
}
void tree_sitter_nasl_external_scanner_deserialize(void *p, const char *b,
                                                   unsigned n) {}

static void advance(TSLexer *lexer) { lexer->advance(lexer, false); }
static void skip(TSLexer *lexer) { lexer->advance(lexer, true); }

static bool scan_template_chars(TSLexer *lexer, enum TokenType tt) {
  bool esc = false, end = false, unquoted_check = true;
  char s = '\0';
  switch (tt) {

  case DOUBLE_FRAGMENT_NO_QUOTED_END:
    unquoted_check = false;
    // fall-through
  case DOUBLE_FRAGMENT:
    s = '"';
    break;
  case SINGLE_FRAGMENT_NO_QUOTED_END:
    unquoted_check = false;
    // fall-through
  case SINGLE_FRAGMENT:
    s = '\'';
    break;
  }

  lexer->mark_end(lexer);
  for (int i = 0;; i++) {
    if (lexer->lookahead == 0)
      return false;
    if (lexer->lookahead == s && !esc) {
      lexer->result_symbol = tt;
      lexer->mark_end(lexer);
      return true;
    }
    // special cases for legacy nasl scripts; due to those it can happen that a rightfully
    // escaped string is missidentified. However parsing through the feed those rules sufficient
    // for now.
    if (lexer->lookahead == s && esc && unquoted_check) {
      lexer->mark_end(lexer);
      advance(lexer);
      for (; lexer->lookahead != s && lexer->lookahead != '\\' &&
             lexer->lookahead != '\n' && lexer->lookahead != ',' &&
             lexer->lookahead != ' ' && !lexer->eof(lexer);
           advance(lexer))
        ;
      if (lexer->lookahead == ',') {
        advance(lexer);

        if (lexer->eof(lexer) || lexer->lookahead == '\n' ||
            lexer->lookahead == ' ')
          return true;
      }
      if (lexer->lookahead == ' ') {
        advance(lexer);
        if (lexer->eof(lexer) || lexer->lookahead == '\n' ||
            lexer->lookahead == '+' || lexer->lookahead == ')' ||
            lexer->lookahead == '&' || lexer->lookahead == ';')
          return true;
      }

      if (lexer->eof(lexer) || lexer->lookahead == '\n')
        return true;

      lexer->mark_end(lexer);
      esc = esc && lexer->lookahead == '\\' ? false : lexer->lookahead == '\\';
      continue;
    }

    esc = esc && lexer->lookahead == '\\' ? false : lexer->lookahead == '\\';
    advance(lexer);
  }
  return false;
}

bool tree_sitter_nasl_external_scanner_scan(void *payload, TSLexer *lexer,
                                            const bool *valid_symbols) {
  if (valid_symbols[SINGLE_FRAGMENT])
    return scan_template_chars(lexer, SINGLE_FRAGMENT);
  if (valid_symbols[DOUBLE_FRAGMENT])
    return scan_template_chars(lexer, DOUBLE_FRAGMENT);
  if (valid_symbols[SINGLE_FRAGMENT_NO_QUOTED_END])
    return scan_template_chars(lexer, SINGLE_FRAGMENT_NO_QUOTED_END);
  if (valid_symbols[DOUBLE_FRAGMENT_NO_QUOTED_END])
    return scan_template_chars(lexer, DOUBLE_FRAGMENT_NO_QUOTED_END);
  return false;
}
