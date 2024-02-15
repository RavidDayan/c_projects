#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "mymat.h"
#include "commands.h"
#include "errors.h"

/*global variables*/
#define MAX_FLOAT_CHAR 9
#define MAX_LINE_LENGTH 200

/*Functions declerations*/
void proccessCommands(mat mats[6]);
void proccessCommand(char *command, int *args, float *tempScalar, mat tempMatrix);
void executeCommand(int *args, mat mats[6], float scalar, mat tempMatrix);
void passWhiteSpace(int *i, char *command);
void getArg(int *i, char *command, int *args, int argNum);
void endOfLine(int i, char *command, int *args);
void printMatrix(mat matrix);
void getMatrix(int *i, char *command, int *args, mat temp);
void getScalar(int *i, char *command, int *args, float *tempScalar);
float getNumber(char *number, int *args);
int isComma(char character);
int isSpace(char character);
/*Functions implementations*/
int main()
{
    mat mats[6];
    int i;
    int row;
    int col;
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
    proccessCommands(mats);
    return 0;
}
void proccessCommands(mat mats[6])
{
    int i;
    char lineBuffer[MAX_LINE_LENGTH];
    int args[4] = {-1, -1, -1, -1};
    float tempScalar;
    mat tempMatrix;
    while (fgets(lineBuffer, sizeof(lineBuffer), stdin) != NULL)
    {
        for (i = 0; i < 4; i++)
        {
            args[i] = -1;
        }
        printf("%s", lineBuffer);
        proccessCommand(lineBuffer, args, &tempScalar, tempMatrix);
        executeCommand(args, mats, tempScalar, tempMatrix);
    }
}
void proccessCommand(char *command, int *args, float *tempScalar, mat tempMatrix)
{
    /*indicates which command is to be executed and additional commands, if [0]=-1 the command is ilegal*/
    int i = 0; /*iterator of the command*/
    /*works down a command tree according to how many args each command needs*/
    initializeMatrix(tempMatrix);
    passWhiteSpace(&i, command);  /*pass empty space*/
    getArg(&i, command, args, 0); /*get first arg*/
    /*check if first arg is good*/
    if (isError(args) == 1)
    {
        return;
    }
    if (args[0] != STOP)
    {
        /*check that the next char is a space or tab*/
        if (isSpace(command[i]) == 0)
        {
            args[0] = ERROR_MISSING_SPACE;
        }
        passWhiteSpace(&i, command);  /*pass empty space*/
        getArg(&i, command, args, 1); /*get second arg*/
        /*check if second arg is good*/
        if (isError(args) == 1)
        {
            return;
        };
        if (args[0] == READ)
        {
            getMatrix(&i, command, args, tempMatrix);
        }
        if (args[0] == MUL_S)
        {
            getScalar(&i, command, args, tempScalar);
        }
        if (args[0] != READ && args[0] != PRINT)
        {
            passWhiteSpace(&i, command); /*pass empty space*/
            if (isComma(command[i] == 0))
            {
                args[0] = ERROR_MISSING_SPACE;
            }
            i++;
            passWhiteSpace(&i, command);  /*pass empty space*/
            getArg(&i, command, args, 2); /*get third args*/
            if (isError(args))
            {
                return;
            };
            if (args[0] != TRANS && args[0] != MUL_S)
            {
                passWhiteSpace(&i, command); /*pass empty space*/
                if (isComma(command[i]) == 0)
                {
                    args[0] = ERROR_MISSING_SPACE;
                }
                i++;
                passWhiteSpace(&i, command); /*pass empty space*/
                getArg(&i, command, args, 3);
            }
        }
    }
    endOfLine(i, command, args);
    /*printf("%c",command[i]);
    printf("%f", *tempScalar);
    printf("%d %d %d %d\n", args[0], args[1], args[2], args[3]);*/
}
void executeCommand(int *args, mat mats[6], float tempScalar, mat tempMatrix)
{
    /*printf("%d",args[0]);
    printf("%d",args[1]);
    printf("%d",args[2]);
    printf("%d\n",args[3]);*/
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
        exit(0);
        break;
    default:
        break;
    }
}
void getArg(int *i, char *command, int *args, int argNum)
{
    char token[11];
    int j = 0;
    int commandNum;
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
        args[0] = -1;
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
    char number[MAX_FLOAT_CHAR + 1];
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
                args[0] = -1;
            }
            (*i)++;
            passWhiteSpace(i, command);
            for (l = 0; l < MAX_FLOAT_CHAR && command[*i] != '\0' && (isdigit(command[*i]) != 0 || command[*i] == '.' || command[*i] == '-'); l++)
            {
                number[l] = command[*i];
                number[l + 1] = '\0';
                (*i)++;
            }
            tempMatrix[j][k] = getNumber(number, args);
            if (command[(*i) + 1] == '\0')
            {
                return;
            }
            if (isError(args) == 1)
            {
                return;
            }
        }
    }
}
void printMatrix(mat matrix)
{
    int i;
    int j;

    for (i = 0; i < MAT_SIZE; i++)
    {
        printf("\n");
        for (j = 0; j < MAT_SIZE; j++)
        {
            printf(" %.2f", matrix[i][j]);
        }
        printf("\n");
    }
}
void getScalar(int *i, char *command, int *args, float *tempScalar)
{
    char number[MAX_FLOAT_CHAR + 1];
    int l;
    passWhiteSpace(i, command);
    if (isComma(command[*i]) == 0)
    {
        args[0] = -1;
    }
    (*i)++;
    passWhiteSpace(i, command);
    for (l = 0; l < MAX_FLOAT_CHAR && (isdigit(command[*i]) != 0 || command[*i] == '.'); l++)
    {
        number[l] = command[*i];
        number[l + 1] = '\0';
        (*i)++;
    }
    *tempScalar = getNumber(number, args);
    passWhiteSpace(i, command);
}
float getNumber(char *number, int *args)
{

    char *endptr;
    double value = strtod(number, &endptr);
    if (*endptr != '\0')
    {
        args[0] = -1;
        return 0;
    }
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