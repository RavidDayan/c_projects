
typedef float mat [4][4];

void add(mat *matA,mat *matB,mat *des);
void sub(mat *matA,mat *matB,mat *des);
void mult(mat *matA,mat *matB,mat *des);
void multS(mat *matA,float scalar,mat *des);
void trans(mat *matA,mat *des);