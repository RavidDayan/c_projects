#include "mymat.h"
#include <stdio.h>

void initializeMatrix(mat matrix)
{
    int i;
    int j;
    for (i = 0; i < MAT_SIZE; i++)
    {
        for (j = 0; j < MAT_SIZE; j++)
        {
            matrix[i][j] = 0;
        }
    }
}
void copy(mat src, mat des)
{
    int i;
    int j;
    for (i = 0; i < MAT_SIZE; i++) /*hard copy of result to destenation matrix*/
    {
        for (j = 0; j < MAT_SIZE; j++)
        {
            des[i][j] = src[i][j];
        }
    }
}
void add(mat matA, mat matB, mat des)
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
void sub(mat matA, mat matB, mat des)
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
void mult(mat matA, mat matB, mat des)
{
    int i;
    int j;
    int k;
    float result; /*sum of the result of each multplying of cell from A and B*/
    mat temp;     /*temporary array to store result*/
    initializeMatrix(temp);
    for (i = 0; i < MAT_SIZE; i++)
    {
        for (j = 0; j < MAT_SIZE; j++)
        {
            result = 0;
            for (k = 0; k < MAT_SIZE; k++)
            {
                result = result + (matA[i][k] * matB[k][j]);
            }
            temp[i][j] = result;
        }
    }
    copy(temp, des);
}
void multS(mat matA, float scalar, mat des)
{
    int i;
    int j;
    for (i = 0; i < MAT_SIZE; i++)
    {
        for (j = 0; j < MAT_SIZE; j++)
        {
            matA[i][j] = matA[i][j] * scalar;
        }
    }
}
void trans(mat matA, mat des)
{
    int i;
    int j;
    mat temp; /*holds the transform until its completed*/
    for (i = 0; i < MAT_SIZE; i++)
    {
        for (j = 0; j < MAT_SIZE; j++)
        {
            temp[i][j] = matA[j][i];
        }
    }
    copy(temp, des);
}
