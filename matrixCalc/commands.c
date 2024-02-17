#include "commands.h"
#include "errors.h"
#include <string.h>

const char *commands[] = {
    "read_mat",
    "print_mat",
    "add_mat",
    "sub_mat",
    "mul_mat",
    "mul_scalar",
    "trans_mat",
    "stop",
    "MAT_A",
    "MAT_B",
    "MAT_C",
    "MAT_D",
    "MAT_E",
    "MAT_F"};

int isMatrix(char *command)
{
    int i;
    for (i = COMMANDS_LENGTH - 6; i < COMMANDS_LENGTH; i++)
    {
        if (strcmp(command, commands[i]) == 0)
        {
            return i - 8;
        }
    }
    return ERROR_NOT_MATRIX;
}
int isCommand(char *command)
{
    int i;
    for (i = 0; i < COMMANDS_LENGTH - 6; i++)
    {
        if (strcmp(command, commands[i]) == 0)
        {
            return i;
        }
    }
    return ERROR_NOT_COMMAND;
}