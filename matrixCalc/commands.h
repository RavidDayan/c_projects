#ifndef COMMANDS_H
#define COMMANDS_H
#define COMMANDS_LENGTH 14 /*const for how many commands and matrix's are int commands matrix*/
#define COMMAND_LENGTH 11  /*maximum size for command buffers*/
/*each const defines a positive number to represent a specific command in the args interpetation */
#define READ 0
#define PRINT 1
#define ADD 2
#define SUB 3
#define MUL 4
#define MUL_S 5
#define TRANS 6
#define STOP 7

extern const char *commands[]; /*array to store every command/matrix name  string*/
int isMatrix(char *command);   /*check if string is a known matrix, returns the matrix place in matrix array,else -1*/
int isCommand(char *command);  /*check if string is a known command, returns the commands place in commands array,else -1*/
#endif