#ifndef MYMAT_H
#define MYMAT_H

#define MAT_SIZE 4                     /*defines the size of the rows and columns of mat */
#define MAX_FLOAT_CHAR 9               /*defines the buffer size for float numbers*/
#define MAX_LINE_LENGTH 200            /*defines the buffer size for reading a line*/
typedef float mat[MAT_SIZE][MAT_SIZE]; /*mat represents a square matrix*/

void initializeMatrix(mat matrix);           /*inserts a zero in eahc cell of matrix*/
void copy(mat matA, mat des);                /*copy's each cell from src matrix to des matrix*/
void add(mat matA, mat matB, mat des);       /*adds each cell from matA and matB and inserts to mat des*/
void sub(mat matA, mat matB, mat des);       /*subtracts each cell from matA and matB and inserts to mat des*/
void mult(mat matA, mat matB, mat des);      /*inserts to each i,j cell in des sum of multiplying each cell in row i from matA with each cell in col j from matB  */
void multS(mat matA, float scalar, mat des); /*multiplys each cell from matA with scalar and inserts to mat des*/
void trans(mat matA, mat des);               /*transoforms each cell i,j from matA to cell j,i in des*/
#endif