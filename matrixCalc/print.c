#include <stdio.h>
#include "mymat.h"
#include "print.h"
#include <math.h>

void startMessage()
{
    printf("Welcome to the matrix Calculator:\nenter lines no longer than %d characters \nenter digits no longer than %d characters\n", MAX_LINE_LENGTH, MAX_FLOAT_CHAR);
}
void enterPrompt()
{
    printf("please enter new prompt\n");
}
void printMatrix(mat matrix)
{
    int i;
    int j;
    int headLength; /*length of gap needed for non decimal digits*/
    headLength = maxNumHeadLength(matrix);
    printf("\n");
    for (i = 0; i < MAT_SIZE; i++)
    {
        for (j = 0; j < MAT_SIZE; j++)
        {
            /*headLength+MAX_DECIMAL_PRINT+2,+2 accounts for ./- and extra space between numbers */
            printf("%*.*f", headLength + MAX_DECIMAL_PRINT + 2, MAX_DECIMAL_PRINT, matrix[i][j]);
        }
        printf("\n");
    }
}
int maxNumHeadLength(mat matrix)
{
    int i;
    int j;
    int length; /*length of gap needed for non decimal digits*/
    int templength;
    float number;
    length = 1;
    for (i = 0; i < MAT_SIZE; i++)
    {
        for (j = 0; j < MAT_SIZE; j++)
        {
            if (matrix[i][j] >= 0)
            {
                number = matrix[i][j];
            }
            else
            {
                number = -matrix[i][j];
            }
            templength = 1;
            /*get the number of digits the non decimal number is smaller than to fit in*/
            while (number > pow(10, templength))
            {
                templength++;
            }
            if (templength > length)
            {
                length = templength;
            }
        }
    }
    return length + 1;
}
void legalStop()
{
    printf("the program has ended successfuly");
}
void ilegalStop()
{
    printf("the program has ended abrouptly,please close next time with command stop\n");
}
