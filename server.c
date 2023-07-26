#include <stdio.h>
int boardLength(int board[3][3]){
    return sizeof(board[0])/sizeof(board[0][0]);
}

void printBoard(int board[3][3]){
    int length=boardLength(board);
    for(int i=0;i<length;i++){
        for(int j=0;j<length;j++){
        printf(" %d",board[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int board[3][3]={{0,0,0},{0,0,0},{0,0,0}};
    printBoard(board);
    return 0;
}