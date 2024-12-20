#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "error.h"

char* err_exename = NULL;

int error(int errtype, char* fmt, ...) {
    va_list va;
    va_start(va, fmt);
    int ret = verror(errtype, fmt, va);
    va_end(va);
    return ret;
}

int verror(int errtype, char* fmt, va_list va) {
    int ret = 0;
    ret += fprintf(stderr, "%s: ", err_exename);
    
    switch (errtype) {
        case E_ERR: ret += fprintf(stderr, "\x1b[31;1merror: \x1b[0m"); break;
        case E_WRN: ret += fprintf(stderr, "\x1b[35;1mwarning: \x1b[0m"); break;
        case E_DBG: ret += fprintf(stderr, "\x1b[32;1mdebug: \x1b[0m"); break;
    }

    ret += vfprintf(stderr, fmt, va);
    if (errtype == E_ERR) exit(1);

    return ret;
}

