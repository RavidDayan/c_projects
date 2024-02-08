#include "mymat.h"

void initializeMatrix(mat *result)
{
    int i;
    int j;
    for (i = 0; i < MAT_SIZE; i++)
    {
        for (j = 0; j < MAT_SIZE; j++)
        {
            result[i][j] = 0;
        }
    }
}

void add(mat *matA, mat *matB, mat *des)
{
    int i;
    int j;
    mat temp;/*temporary array to store result*/
    initializeMatrix(temp);
    for (i = 0; i < MAT_SIZE; i++)
    {
        for (j = 0; j < MAT_SIZE; j++)
        {
            temp[i][j] = matA[i][j] + matB[i][j];
        }
    }
    for (i = 0; i < MAT_SIZE; i++)/*hard copy of result to destenation matrix*/
    {
        for (j = 0; j < MAT_SIZE; j++)
        {
            des[i][j] = temp[i][j];
        }
    }
}
void sub(mat *matA, mat *matB, mat *des)
{
}
void mult(mat *matA, mat *matB, mat *des)
{
}
void multS(mat *matA, float scalar, mat *des)
{
}
void trans(mat *matA, mat *des)
{
}
