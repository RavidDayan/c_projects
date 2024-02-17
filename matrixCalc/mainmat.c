#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "mymat.h"
#include "commands.h"
#include "errors.h"
#include "print.h"
/*############## notes ##############
1. there is no prompt to enter commands because commands only come from other files and there is no keyboard so there is no waiting for
   insertation ,if this was reading from  keyboard the promt would be printed before each fgets
2. maximum number of digits of float numbers,size of matrixs and line characters are defined in mymat.h and can be changed there to affect the whole program
3. the printing is adjusted to be as small as possible but fit the longest number in each matrix
  ###################################*/

/*Functions declerations*/
/*proccess all commands line by line and then executes each command or error if command is not correct*/
void proccessCommands(mat mats[6]);
/*breaks the command up to 4 arguments or other special command needs,stores the interpetation of
command inside an int array [command,arg1,arg2,arg3] positive commands are commands negative commands are errors,
incase of error the proccess is stopped without checking the rest of the command*/
void proccessCommand(char *command, int *args, float *tempScalar, mat tempMatrix);
/*executes the command by the interpetation of the int array according to, incase of error prints the appropriate error*/
void executeCommand(int *args, mat mats[6], float scalar, mat tempMatrix);
/*passes all white spaces until reaches a non whitespace character*/
void passWhiteSpace(int *i, char *command);
/*gets an arg from command until it reaches a whitespace */
void getArg(int *i, char *command, int *args, int argNum);
/*checks the rest of the remaining line to see if there are no other characters other than whitespace*/
void endOfLine(int i, char *command, int *args);
/*retrives the matrix from command, can get a float up to MAX_FLOAT_CHAR digits*/
void getMatrix(int *i, char *command, int *args, mat temp);
/*retrives the scalar from command, can get a float up to MAX_FLOAT_CHAR digits*/
void getScalar(int *i, char *command, int *args, float *tempScalar);
/*gets a str of a float number and returns the number in float type, if the string is not a float signals error*/
float getNumber(char *number, int *args);
/*check if character is a ,*/
int isComma(char character);
/*check if character is space or tab ,*/
int isSpace(char character);
/*Functions implementations*/
int main()
{
    mat mats[6];
    int i;
    int row;
    int col;
    /*initialize's all matrix's to 0 value*/
    for (i = 0; i < 6; i++)
    {
        for (row = 0; row < MAT_SIZE; row++)
        {
            for (col = 0; col < MAT_SIZE; col++)
            {
                mats[i][row][col] = 0.0;
            }
        }
    }
    startMessage();
    proccessCommands(mats);
    /*if code didnt stop with stop command it will get here and print an ilegal stop message*/
    ilegalStop();
    return 0;
}
void proccessCommands(mat mats[6])
{
    int i;
    char lineBuffer[MAX_LINE_LENGTH]; /*buffer to hold line read from input*/
    /*args acts as a buffer for arguments extracted from line but as numbers
    arg[0]:command arg[1]=matrix,arg[2]=matrix,arg[3]=matrix*
    incase a matrix cell is not needed it is -1*/
    int args[4] = {-1, -1, -1, -1};
    float tempScalar; /*holds the scalar extracted from command if there is one*/
    mat tempMatrix;   /*holds the matrix read from command line, otherwise 0 matrix*/

    /*get each line of redirection document*/
    while (fgets(lineBuffer, sizeof(lineBuffer), stdin) != NULL)
    {
        for (i = 0; i < 4; i++) /*initialize the args*/

        {
            args[i] = -1;
        }
        printf("%s", lineBuffer); /*print each line read from input*/
        proccessCommand(lineBuffer, args, &tempScalar, tempMatrix);
        executeCommand(args, mats, tempScalar, tempMatrix);
    }
}
void proccessCommand(char *command, int *args, float *tempScalar, mat tempMatrix)
{
    int i = 0; /*iterator of the command*/
    /*works down a command tree according to how many args each command needs*/
    initializeMatrix(tempMatrix); /*zero all matrix cells*/
    passWhiteSpace(&i, command);  /*pass empty space*/
    if (isComma(command[i]) == 1) /*check for ilegal comma*/
    {
        args[0] = ERROR_ILLEGAL_COMMA;
        return;
    }
    getArg(&i, command, args, 0); /*get first arg*/
    if (isError(args) == 1)       /*check if first arg is not an error, stop running if it is*/
    {
        return;
    }
    if (args[0] != STOP) /*only stop needs 1 arg so unless its stop move to 2nd arg*/
    {
        if (isSpace(command[i]) == 0) /*check that the next char is a space or tab*/
        {
            args[0] = ERROR_MISSING_SPACE;
        }
        passWhiteSpace(&i, command);  /*pass empty space*/
        if (isComma(command[i]) == 1) /*check for ilegal comma*/
        {
            args[0] = ERROR_ILLEGAL_COMMA;
            return;
        }
        getArg(&i, command, args, 1); /*get second arg*/
        if (isError(args) == 1)       /*check if second arg is not an error, stop running if it is*/
        {
            return;
        };
        if (args[0] == READ)
        {
            getMatrix(&i, command, args, tempMatrix);
            if (isError(args))
            {
                return;
            };
        }
        if (args[0] == MUL_S)
        {
            getScalar(&i, command, args, tempScalar);
            if (isError(args))
            {
                return;
            };
        }
        /*only read and print need 2 arguments all other need 3 or more*/
        if (args[0] != READ && args[0] != PRINT)
        {
            passWhiteSpace(&i, command); /*pass empty space*/
            if (isComma(command[i]) == 0)
            {
                args[0] = ERROR_MISSING_COMMA;
                return;
            }
            i++;                          /*move to next char after comma*/
            passWhiteSpace(&i, command);  /*pass empty space*/
            if (isComma(command[i]) == 1) /*check for ilegal comma*/
            {
                args[0] = ERROR_CONSECUTIVE_COMMA;
                return;
            }
            getArg(&i, command, args, 2); /*get third arg*/
            if (isError(args))
            {
                return;
            };
            /*only trans and mul_s need 3 args all other need 4*/
            if (args[0] != TRANS && args[0] != MUL_S)
            {
                passWhiteSpace(&i, command); /*pass empty space*/
                if (isComma(command[i]) == 0)
                {
                    args[0] = ERROR_MISSING_COMMA;
                }
                i++;                          /*move to next char after comma*/
                passWhiteSpace(&i, command);  /*pass empty space*/
                if (isComma(command[i]) == 1) /*check for ilegal comma*/
                {
                    args[0] = ERROR_CONSECUTIVE_COMMA;
                    return;
                }
                getArg(&i, command, args, 3); /*get fourth arg*/
                if (isError(args))
                {
                    return;
                };
            }
        }
    }
    endOfLine(i, command, args); /*check for now extra characters other than whitespace afterr all commands*/
}
void executeCommand(int *args, mat mats[6], float tempScalar, mat tempMatrix)
{
    /*to avoid alot of checking the execution is split to errors and commands */
    if (args[0] >= 0)
    {
        switch (args[0])
        {
        case READ:
            copy(tempMatrix, mats[args[1]]);
            break;
        case PRINT:
            printMatrix(mats[args[1]]);
            break;
        case ADD:
            add(mats[args[1]], mats[args[2]], mats[args[3]]);
            break;
        case SUB:
            sub(mats[args[1]], mats[args[2]], mats[args[3]]);
            break;
        case MUL:
            mult(mats[args[1]], mats[args[2]], mats[args[3]]);
            break;
        case MUL_S:
            multS(mats[args[1]], tempScalar, mats[args[2]]);
            break;
        case TRANS:
            trans(mats[args[1]], mats[args[2]]);
            break;
        case STOP:
            legalStop();
            exit(0);
            break;
        default:
            break;
        }
    }
    else
    {
        switch (args[0])
        {
        case ERROR_NOT_COMMAND:
            notCommandError();
            break;
        case ERROR_NOT_MATRIX:
            notMatrixError();
            break;
        case ERROR_MISSING_COMMA:
            missingCommaError();
            break;
        case ERROR_NOT_REAL_NUMBER:
            notRealNumberError();
            break;
        case ERROR_ILLEGAL_EXTRA_CHARACTERS:
            extraCharactersError();
            break;
        case ERROR_MISSING_SPACE:
            missingSpaceError();
            break;
        case ERROR_ILLEGAL_COMMA:
            ilegalCommaError();
            break;
        case ERROR_CONSECUTIVE_COMMA:
            consecutiveCommaError();
            break;
        case ERROR_NO_SCALAR:
            noScalarError();
            break;
        default:
            break;
        }
    }
}
void getArg(int *i, char *command, int *args, int argNum)
{
    int j = 0;
    char token[COMMAND_LENGTH]; /*buffer to hold the command extracted from line*/
    int commandNum;             /*holds the represing number of command*/
    /*get first token,check for comma or white space or end of string*/
    while (isspace(command[*i]) == 0 && command[*i] != ',' && command[*i] != '\0')
    {
        if (j < 10) /*no arg should be more than 10 characters*/
        {
            token[j] = command[*i];
            token[j + 1] = '\0';
            j++;
        }
        (*i)++;
    }
    if (argNum == 0)
    {
        commandNum = isCommand(token);
    }
    else
    {
        commandNum = isMatrix(token);
    }
    if (commandNum >= 0)
    {
        args[argNum] = commandNum;
    }
    else
    {
        args[0] = commandNum;
    }
}
void endOfLine(int i, char *command, int *args)
{
    passWhiteSpace(&i, command);
    /*last character in line should be \0*/
    if (command[i] != '\0')
    {
        args[0] = ERROR_ILLEGAL_EXTRA_CHARACTERS;
    }
}
void getMatrix(int *i, char *command, int *args, mat tempMatrix)
{
    char number[MAX_FLOAT_CHAR + 1]; /*string to hold string of the number as chars*/
    int k;
    int j;
    int l;
    for (j = 0; j < MAT_SIZE; j++)
    {
        for (k = 0; k < MAT_SIZE; k++)
        {
            passWhiteSpace(i, command);
            if (isComma(command[*i]) == 0)
            {

                args[0] = ERROR_MISSING_COMMA;
                return;
            }
            (*i)++;
            passWhiteSpace(i, command);
            for (l = 0; l < MAX_FLOAT_CHAR && command[*i] != '\0' && (isdigit(command[*i]) != 0 || command[*i] == '.' || command[*i] == '-'); l++)
            {
                number[l] = command[*i];
                number[l + 1] = '\0';
                (*i)++;
            }
            if (l == 0)
            {
                args[0] = ERROR_NOT_REAL_NUMBER;
                return;
            }
            tempMatrix[j][k] = getNumber(number, args);
            /*\0 signals end of line so we finish reading*/
            if (command[(*i) + 1] == '\0')
            {
                return;
            }
            /*look for error in each reading of number*/
            if (isError(args) == 1)
            {
                return;
            }
        }
    }
}
void getScalar(int *i, char *command, int *args, float *tempScalar)
{
    char number[MAX_FLOAT_CHAR + 1]; /*string to hold string of the number as chars*/
    int l;
    passWhiteSpace(i, command);
    if (isComma(command[*i]) == 0)
    {
        args[0] = ERROR_MISSING_COMMA;
    }
    (*i)++;
    passWhiteSpace(i, command);
    for (l = 0; l < MAX_FLOAT_CHAR && (isdigit(command[*i]) != 0 || command[*i] == '.'); l++)
    {
        number[l] = command[*i];
        number[l + 1] = '\0';
        (*i)++;
    }
    if (l == 0)
    {
        args[0] = ERROR_NO_SCALAR;
        return;
    }
    *tempScalar = getNumber(number, args);
    passWhiteSpace(i, command);
}
float getNumber(char *number, int *args)
{
    char *endptr;                           /*pointer where the transformation stropped*/
    double value = strtod(number, &endptr); /*convert string chars to float*/
    return value;
}
void passWhiteSpace(int *i, char *command)
{
    while (isspace(command[*i]) != 0)
    {
        (*i)++;
    }
}
int isComma(char character)
{
    if (character == ',')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isSpace(char character)
{
    if (character == ' ' || character == '\t')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}