#include "commands.h"
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
    "MAT_R",
    "MAT_E"
};

int isMatrix(char *command)
{
    int i;
    for (i = COMMANDS_LENGTH - 6; i < COMMANDS_LENGTH; i++)
    {
        if (strcmp(command, commands[i]) == 0)
        {
            return COMMANDS_LENGTH - i;
        }
    }
    return -1;
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
    return -1;
}