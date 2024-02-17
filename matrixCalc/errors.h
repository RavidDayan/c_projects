#ifndef ERRORS_H
#define ERRORS_H
/*each const defines a negative number to represent a specific error in the args interpetation */
#define ERROR_NOT_COMMAND -1
#define ERROR_NOT_MATRIX -2
#define ERROR_MISSING_COMMA -3
#define ERROR_NOT_REAL_NUMBER -4
#define ERROR_ILLEGAL_EXTRA_CHARACTERS -5
#define ERROR_MISSING_SPACE -6
#define ERROR_ILLEGAL_COMMA -7
#define ERROR_CONSECUTIVE_COMMA -8
#define ERROR_NO_SCALAR -9

int isError(int *args); /*recieves an arg representing int and return's if its an error or not (negtaive number is an error,postive command) */
/*print function for each error available*/
void notCommandError();
void notMatrixError();
void missingCommaError();
void notRealNumberError();
void extraCharactersError();
void missingSpaceError();
void ilegalCommaError();
void consecutiveCommaError();
void noScalarError();
#endif