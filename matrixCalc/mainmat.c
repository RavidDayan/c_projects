#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "mymat.h"
#include "commands.h"
#include "errors.h"

/*global variables*/
#define MAX_FLOAT_CHAR 9

/*Functions declerations*/
void proccessCommands(FILE *inputCommands,mat **mats);
void proccessCommand(char *command, int *args,float *tempScalar, mat tempMatrix);
void executeCommand(int *args, mat **mats, float scalar, mat tempMatrix);
int passWhiteSpace(int i, char *command);
int arg1(int i, char *command, int *args);
int arg2(int i, char *command, int *args);
int arg3(int i, char *command, int *args);
int arg4(int i, char *command, int *args);
void endOfLine(int i, char *command, int *args);
int printMatrix(mat matrix);
int getMatrix(int i, char *command, int *args, mat temp);
int getScalar(int i, char *command, int *args);
int isComma(char character);
/*Functions implementations*/
int main()
{
    mat *mats[6];
    FILE *inputCommands = stdin;
    fseek(inputCommands, 0, SEEK_SET);
    proccessCommands(inputCommands,mats);
    return 0;
}
void proccessCommands(FILE *inputCommands, mat **mats)
{
    int args[4] = {-1, -1, -1, -1};
    char *command = NULL;
    float tempScalar;
    mat tempMatrix;
    int len = 0;

    while (getline(inputCommands, command) != -1)
    {
        proccessCommand(command, args, &tempScalar, tempMatrix);
        executeCommand(args, mats, tempScalar, tempMatrix);
        free(command);
    }
    free(command);
}
void proccessCommand(char *command, int *args, float *tempScalar, mat tempMatrix)
{
    /*indicates which command is to be executed and additional commands, if [0]=-1 the command is ilegal*/
    int i = 0; /*iterator of the command*/
    /*works down a command tree according to how many args each command needs*/
    i = arg1(i, command, args);
    if (isError(args))
    {
        return;
    }
    if (args[0] != STOP)
    {
        i = arg2(i, command, args);
        if (isError(args))
        {
            return;
        };
        if (args[0] == READ)
        {
            i = getMatrix(i, command, args, tempMatrix);
        }
        if (args[0] == MUL_S)
        {
            i = getScalar(i, command, args);
        }
        if (args[0] != READ && args[0] != MUL_S)
        {
            i = arg3(i, command, args);
            if (isError(args))
            {
                return;
            };
            if (args[0] != TRANS)
            {
                i = arg4(i, command, args);
            }
        }
    }
    endOfLine(i, command, args);
}
void executeCommand(int *args, mat **mats, float tempScalar, mat tempMatrix)
{
    switch (args[0])
    {
    case READ:
        /* add(mats[args[1]], mats[args[2]],tempMatrix);*/
        break;
    case PRINT:
        /*printMatrix(mats[args[1]]);*/
        break;
    case ADD:
        add(*mats[args[1]], *mats[args[2]], *mats[args[3]]);
        break;
    case SUB:
        sub(*mats[args[1]], *mats[args[2]], *mats[args[3]]);
        break;
    case MUL:
        mult(*mats[args[1]], *mats[args[2]], *mats[args[3]]);
        break;
    case MUL_S:
        multS(*mats[args[1]], tempScalar, *mats[args[3]]);
        break;
    case TRANS:
        add(*mats[args[1]], *mats[args[2]], *mats[args[3]]);
        break;
    case STOP:
        exit(0);
        break;
    default:
        break;
    }
}
void getLine(char *inputCommands, char *command) {}
/*gets the first arguments of the command*/
int arg1(int i, char *command, int *args)
{
    char token[11];
    int j = 0;
    i = passWhiteSpace(i, command);
    /*get first token,check for comma or white space or end of string*/
    while (isspace(command[i]) == 0 && command[i] != '\0')
    {
        if (j < 10) /*no arg should be more than 10 characters*/
        {
            token[j] = command[i];
            token[j + 1] = '\0';
            j++;
        }
        i++;
    }
    args[0] = isCommand(token);
    return i;
}
int arg2(int i, char *command, int *args)
{
    char token[5];
    int j = 0;
    int result;
    /*check if the char is a tab or whitespace*/
    if (command[i] != ' ' && command[i] != '\t')
    {
        args[0] = -1;
        return i;
    }
    i = passWhiteSpace(i, command);
    /*get second token,check for comma or white space or end of string*/
    while (isspace(command[i]) == 0 && command[i] != '\0')
    {
        if (j < 10) /*no arg should be more than 10 characters*/
        {
            token[j] = command[i];
            token[j + 1] = '\0';
            j++;
        }
        i++;
    }
    result = isMatrix(token);
    if (result == -1)
    {
        args[0] = result;
    }
    else
    {
        args[1] = result;
    }
    return i;
}
int arg3(int i, char *command, int *args)
{
    char token[5];
    int j = 0;
    int result;
    i = passWhiteSpace(i, command);
    /*get second token,check for comma or white space or end of string*/
    if (isComma(command[i]) == 0)
    {
        args[0] = -1;
        return i;
    }
    i = passWhiteSpace(i, command);
    if (isComma(command[i]) == 0)
    {
        args[0] = -1;
        return i;
    }
    while (isspace(command[i]) == 0 && command[i] != '\0')
    {
        if (j < 10) /*no arg should be more than 10 characters*/
        {
            token[j] = command[i];
            token[j + 1] = '\0';
            j++;
        }
        i++;
    }
    result = isMatrix(token);
    if (result == -1)
    {
        args[0] = result;
    }
    else
    {
        args[1] = result;
    }
    return i;
}
int arg4(int i, char *command, int *args)
{
    char token[5];
    int j = 0;
    int result;
    i = passWhiteSpace(i, command);
    /*get second token,check for comma or white space or end of string*/
    if (isComma(command[i]) == 0)
    {
        args[0] = -1;
        return i;
    }
    i = passWhiteSpace(i, command);
    if (isComma(command[i]) == 0)
    {
        args[0] = -1;
        return i;
    }
    while (isspace(command[i]) == 0 && command[i] != '\0')
    {
        if (j < 10) /*no arg should be more than 10 characters*/
        {
            token[j] = command[i];
            token[j + 1] = '\0';
            j++;
        }
        i++;
    }
    result = isMatrix(token);
    if (result == -1)
    {
        args[0] = result;
    }
    else
    {
        args[1] = result;
    }
    return i;
}
/*check to see if there are no other characters other than whitespaces or \0*/
void endOfLine(int i, char *command, int *args)
{
    i = passWhiteSpace(i, command);
    /*last character in line should be \0*/
    if (command[i] != '\0')
    {
        args[0] = ERROR_ILLEGAL_EXTRA_CHARACTERS;
    }
}
int getMatrix(int i, char *command, int *args, mat tempMatrix)
{
    char number[MAX_FLOAT_CHAR + 1];
    int k;
    int j;
    int l;
    for (j = 0; j < MAT_SIZE; j++)
    {
        for (k = 0; k < MAT_SIZE; k++)
        {
            i = passWhiteSpace(i, command);
            for (l = 0; l < MAX_FLOAT_CHAR && (isdigit(command[i]) != 0 || command[i] == '.'); l++)
            {
                number[l] = command[i];
                number[l + 1] = '\0';
            }
            i = passWhiteSpace(i, command);
        }
    }
}
int printMatrix(mat matrix)
{
    int i;
    int j;
    for (i = 0; i < MAT_SIZE; i++)
    {
        for (j = 0; j < MAT_SIZE; j++)
        {
            printf("%f", matrix[i][j]);
        }
        printf("\n");
    }
}
int getScalar(int i, char *command, int *args) {}
float getNumber(int i, char *command, int *args)
{
    char number[MAX_FLOAT_CHAR + 1];
    int j;
    i = passWhiteSpace(i, command);
    for (j = 0; j < MAX_FLOAT_CHAR && (isdigit(command[i]) != 0 || command[i] == '.'); j++)
    {
        number[j] = command[i];
        number[j + 1] = '\0';
    }
    i = passWhiteSpace(i, command);
}
/*iterates all white spaces and returns the index of the first non whitespace char*/
int passWhiteSpace(int i, char *command)
{
    while (isspace(command[i]) != 0)
    {
        i++;
    }
    return i;
}
/*checks if char is a comma,1 true -1 false*/
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