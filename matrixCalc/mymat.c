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
void copy(mat *matA, mat *des)
{
    for (i = 0; i < MAT_SIZE; i++) /*hard copy of result to destenation matrix*/
    {
        for (j = 0; j < MAT_SIZE; j++)
        {
            des[i][j] = matA[i][j];
        }
    }
}
void add(mat *matA, mat *matB, mat *des)
{
    int i;
    int j;
    mat temp; /*temporary array to store result*/
    initializeMatrix(temp);
    for (i = 0; i < MAT_SIZE; i++)
    {
        for (j = 0; j < MAT_SIZE; j++)
        {
            temp[i][j] = matA[i][j] + matB[i][j];
        }
    }
    copy(temp, des);
}
void sub(mat *matA, mat *matB, mat *des)
{
    int i;
    int j;
    mat temp; /*temporary array to store result*/
    initializeMatrix(temp);
    for (i = 0; i < MAT_SIZE; i++)
    {
        for (j = 0; j < MAT_SIZE; j++)
        {
            temp[i][j] = matA[i][j] - matB[i][j];
        }
    }
    copy(temp, des);
}
void mult(mat *matA, mat *matB, mat *des)
{
    int i;
    int j;
    int k;
    mat temp; /*temporary array to store result*/
    initializeMatrix(temp);
    for (i = 0; i < MAT_SIZE; i++)
    {
        for (j = 0; j < MAT_SIZE; j++)
        {
            for (k = 0; k < MAT_SIZE; k++)
            {

                temp[i][j] = matA[i][k] * matA[k][j];
            }
        }
    }
    copy(temp,des);
}
void multS(mat *matA, float scalar, mat *des)
{
    int i;
    int j;
    for (i = 0; i < MAT_SIZE; i++)
    {
        for (j = 0; j < MAT_SIZE; j++)
        {
            temp[i][j] = matA[i][j] * scalar;
        }
    }
}
void trans(mat *matA, mat *des)
{
    int i;
    int j;
    for (i = 0; i < MAT_SIZE; i++)
    {
        for (j = 0; j < MAT_SIZE; j++)
        {
            temp[j][i] = matA[i][j];
        }
    }
    copy(temp,des);
}
