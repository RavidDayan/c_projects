#include <stdio.h>
#include <stdbool.h>

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

void getPlayerInput(int *board[3][3]){
    int input;
    do{
        printf("please enter a number between 1 to 9 :");
        scanf("%d",&input);
        if(isCellLegal(input)==0){
            printf("invalid cell number, please try again");
        }
        if (canBeInserted(*board,input)==0)
        {
            printf("cell is taken, please try again");
        }
        
    }while(isCellLegal==0 || canBeInserted==0);
    return input;
}
int canBeInserted(int *board[3][3],int index){
    return (*board[getRow(index)][getCOL(index)]==0)?1:0;
}
int isCellLegal(int index){
    return (index<1 || index>9)?1:0;
}
int getRow(int cell){
    return (cell-1)/3;
}
int getCol(int cell){
        return (cell-1)%3;
}
void insertInput(int index,int sign,int *board[3][3]){
    *board[getRow(index)][getCol(index)]=sign;
}
int main(){
    int board[3][3]={{0,0,0},{0,0,0},{0,0,0}};
    enum Signs{x=1,o=2};
    enum Signs playerSign;
    bool winner=false;
    int rounds=7;
    /*while(winner && rounds==9){
        rounds=rounds+1;

    }*/
    return 0;
}