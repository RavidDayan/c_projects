#include <stdio.h>
#include "mymat.c"

int main(){
    int i;
    int j;
    mat temp;
    initializeMatrix(temp);
    temp[1][1]=10;
    for (i = 0; i < MAT_SIZE; i++) /*hard copy of result to destenation matrix*/
    {
        for (j = 0; j < MAT_SIZE; j++)
        {
               printf("%f",temp[i][j]); 
        }
    }
    printf("hello");
    return 0;
}