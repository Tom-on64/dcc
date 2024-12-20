#ifndef LEXER_H
#define LEXER_H

#include <stdio.h>

#define DEF_TKNLIST_LEN 16

/* Token Types */
typedef enum {
    T_INVALID,

    /* Keywords */
    T_INT,
    T_RETURN,

    /* Literals */
    T_LIT_INT,

    /* Special */
    T_LBRACE,
    T_RBRACE,
    T_LPAREN,
    T_RPAREN,

    /* Misc. */
    T_IDENT,
    T_EOL,
    T_EOF,
} TokType;

/* Token */
typedef struct {
    TokType type; // Token Type
    union { // Token value
        unsigned int u32;
        char* str;
    }; 
    int row; // Row in file
    int col; // Column in file
} Token;

/* Token List */
typedef struct {
    Token* list;    
    int len;
    int maxlen;
} TokenList;

/* Functions */
TokenList* lex(char* file);

void lexIdent();
void lexInt();
void lexSpecial();

TokenList* newTokenList();
void freeTokenList(TokenList* tokens);
void addToken(TokenList* tokens, Token token);

#endif
