#ifndef LEXER_H
#define LEXER_H

typedef enum {
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

typedef struct {
    TokType type;
    char* val;
} Token;

#endif
