#include "cli.h"

commands[] = {
    "read_mat\0",
    "print_mat\0",
    "add_mat\0",
    "sub_mat\0",
    "mul_mat\0",
    "mul_scalar\0",
    "trans_mat\0",
    "stop\0",
    "MAT_A\0",
    "MAT_B\0",
    "MAT_C\0",
    "MAT_D\0",
    "MAT_R\0",
    "MAT_E\0"
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