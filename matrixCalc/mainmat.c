#include <stdio.h>
#include <stdlib.h>
#include "mymat.h"

/*global variables*/
#define inputFile "input.txt"

/*Functions declerations*/
void proccessCommands(char *fileName);
void proccessCommand(char *command);
void executeCommand(char *command);

/*Functions implementations*/
int main()
{
    mat MAT_A;
    mat MAT_B;
    mat MAT_C;
    mat MAT_D;
    mat MAT_E;
    mat MAT_F;
    mat *Mats[6] = {&MAT_A,&MAT_B,&MAT_C,&MAT_D,&MAT_E,&MAT_F};
     proccessCommands(inputFile);
    return 0;
}

void proccessCommands(char *fileName)
{
    FILE *file = fopen(fileName, "r");
    if (file == NULL)
    {
        perror("Error opening file");
    }

    char *command = NULL;
    size_t len = 0;

    while (getline(&command, &len, file) != -1)
    {
        printf("%s",command);
    }
    free(command);
    fclose(file);
}
void proccessCommand(char *command)
{
}
void executeCommand(char *command) {}
