#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "error.h"
#include "lexer.h"

struct {
    char* file;
    int idx;
    TokenList* tokens;
    int row;
    int col;
} T;

TokenList* lex(char* file) {
    T.file = file;
    T.idx = 0;
    T.tokens = newTokenList();
    T.row = 1;
    T.col = 0; // Will be immediatly incremented to 1

    char c = '\0';
    while ((c = T.file[T.idx]) != '\0') {
        // Update file postion
        T.col++;
        if (c == '\n') {
            T.col = 0;
            T.row++;
        }

        if (isspace(c)); // Skip whitespace
        else if (isalpha(c) || c == '_') lexIdent();
        else if (isdigit(c)) lexInt();
        else lexSpecial();

        T.idx++;
    }

    Token endoffile = { T_EOF, { 0 }, T.row, T.col };
    addToken(T.tokens, endoffile);

    return T.tokens; 
}

void lexIdent() {

}

void lexInt() {
    char str[64] = { 0 };
}

void lexSpecial() {
    char c = T.file[T.idx++];

    Token t = { 0 };
    t.row = T.row;
    t.col = T.col;

    // Figure out type
    switch (c) {
        case '(': t.type = T_LPAREN; break;
        case ')': t.type = T_RPAREN; break;
        // case '[': t.type = T_LBRACE; break;
        // case ']': t.type = T_LBRACE; break;
        case '{': t.type = T_LBRACE; break;
        case '}': t.type = T_RBRACE; break;
        case ';': t.type = T_EOL; break;
        default: error(E_ERR, "unexpected character at %d:%d.", T.row, T.col); break;
    }

    addToken(T.tokens, t);
}

void lexerExpect(FILE* file, char c) {
    char exp = fgetc(file);
    if (exp != c) error(E_ERR, "expected '%c' at %d:%d.", c, T.row, T.col);
}

void freeTokenList(TokenList* tokens) {
    free(tokens->list);
    free(tokens);
}

TokenList* newTokenList() {
    TokenList* tokens = malloc(sizeof(TokenList));
    if (tokens == NULL) error(E_ERR, "not enough memory.\n");

    tokens->maxlen = DEF_TKNLIST_LEN;
    tokens->len = 0;
    tokens->list = malloc(sizeof(Token) * tokens->maxlen);
    if (tokens->list == NULL) error(E_ERR, "not enough memory.\n");

    return tokens;
}

void addToken(TokenList* tokens, Token token) {
    if (tokens->len >= tokens->maxlen) {
        tokens->maxlen *= 2;
        tokens->list = realloc(tokens->list, tokens->maxlen * sizeof(Token));

        if (tokens->list == NULL) error(E_ERR, "not enough memory.\n");
    }

    tokens->list[tokens->len++] = token;
}


