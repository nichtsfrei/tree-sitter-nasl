#include <tree_sitter/parser.h>
#include <stdio.h>
#include <wctype.h>
enum TokenType {
  DOUBLE_FRAGMENT,
  SINGLE_FRAGMENT,
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

static bool valid_escape(char s, char n){
  return n == 'n' || n == s || n == '\\';
} 

static bool scan_template_chars(TSLexer *lexer, enum TokenType tt) {
  char s = '\0';

  bool esc = false;
  switch (tt) {

  case DOUBLE_FRAGMENT:
    s = '"';
    break;
  case SINGLE_FRAGMENT:
    s = '\'';
    break;
  }

  lexer->mark_end(lexer);
  for (int i = 0;; i++) {
    if (lexer->lookahead == 0)
      return false;
    // on " we don't allow \"
    if (lexer->lookahead == s && (tt == DOUBLE_FRAGMENT || !esc)) {
      lexer->result_symbol = tt;
      lexer->mark_end(lexer);
      return true;
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
  return false;
}
