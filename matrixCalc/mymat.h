#ifndef MYMAT_H
#define MYMAT_H

#define MAT_SIZE 4
#define MAX_FLOAT_CHAR 9
#define MAX_LINE_LENGTH 200
typedef float mat[MAT_SIZE][MAT_SIZE];

void initializeMatrix(mat matrix);
void copy(mat matA, mat des);
void add(mat matA, mat matB, mat des);
void sub(mat matA, mat matB, mat des);
void mult(mat matA, mat matB, mat des);
void multS(mat matA, float scalar, mat des);
void trans(mat matA, mat des);
#endif