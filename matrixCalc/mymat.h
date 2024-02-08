
#define MAT_SIZE 4
typedef float mat [MAT_SIZE][MAT_SIZE];

void add(mat *matA,mat *matB,mat *des);
void sub(mat *matA,mat *matB,mat *des);
void mult(mat *matA,mat *matB,mat *des);
void multS(mat *matA,float scalar,mat *des);
void trans(mat *matA,mat *des);
void initializeMatrix(mat *result);
void copy(mat *matA,mat *des);