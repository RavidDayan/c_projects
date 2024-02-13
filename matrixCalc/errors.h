#ifndef ERRORS_H
#define ERRORS_H
#define ERROR_NOT_COMMAND -1
#define ERROR_NOT_MATRIX -2
#define ERROR_MISSING_ARG -3
#define ERROR_NOT_REAL_NUMBER -4
#define ERROR_ILLEGAL_COMMA -5
#define ERROR_ILLEGAL_EXTRA_CHARACTERS -6

int isError(int *args);
#endif