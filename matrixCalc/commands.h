#ifndef COMMANDS_H
#define COMMANDS_H
#define COMMANDS_LENGTH 14
#define COMMAND_LENGTH 11
#define READ 0
#define PRINT 1
#define ADD 2
#define SUB 3
#define MUL 4
#define MUL_S 5
#define TRANS 6
#define STOP 7
extern const char *commands;
/*check if string is a known matrix, returns the matrix place in matrix array,else -1*/
int isMatrix(char *command);
/*check if string is a known command, returns the commands place in commands array,else -1*/
int isCommand(char *command);
#endif