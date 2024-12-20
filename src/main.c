#include <stdlib.h>
#include <stdio.h>
#include "error.h"
#include "lexer.h"

void handleoption(char opt);

int main(int argc, char** argv) {
    err_exename = argv[0];  // Assign exe name for error printing
    char* infile = NULL;
    char* outfile = "out.s";

    // Parse command line options
    for (int i = 1; i < argc; i++) { // Start at one to skip the exe name
        if (argv[i][0] != '-') { // Not an option
            if (infile != NULL) error(E_WRN, "multiple input files given, will compile last.\n");
            infile = argv[i];
            continue;
        }

        char opt = argv[i][1];
        // Check if there is an option
        if (opt == '\0') error(E_ERR, "expected option after '-'.\n");

        // TODO: Add more options
        if (opt == 'o') {
            if (i + 1 >= argc) error(E_ERR, "no output file given.\n");
            outfile = argv[++i];
        }
    }

    // Check if user entered a file
    if (infile == NULL) error(E_ERR, "no input file given.\n");

    // Read file
    FILE* fp = fopen(infile, "r");
    if (fp == NULL) error(E_ERR, "input file not found.\n");
    fseek(fp, 0, SEEK_END);
    long fsize = ftell(fp);
    rewind(fp);

    char* buf = malloc(fsize + 1);
    if (fread(buf, fsize, 1, fp) != 1) error(E_ERR, "failed to read file.\n");
    fclose(fp);
    buf[fsize] = '\0';

    // Lexer
    
    
    free(buf);
    return 0;
}

