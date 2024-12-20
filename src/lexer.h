#ifndef LEXER_H
#define LEXER_H

#include <stdio.h>

#define DEF_TKNLIST_LEN 16
#define MAX_IDENT_LEN   64  // Includes terminating NULL

/* Token Types */
typedef enum {
    T_INVALID,

    /* Keywords */
    T_INT,
    T_RETURN,

    /* Literals */
    T_LIT_INT,

    /* Special */
    T_LPAREN,
    T_RPAREN,
    T_LBRACKET,
    T_RBRACKET,
    T_LBRACE,
    T_RBRACE,

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
int lexKeyword(char* str);
void lexInt();
void lexSpecial();

TokenList* newTokenList();
void freeTokenList(TokenList* tokens);
void addToken(TokenList* tokens, Token token);

#endif
