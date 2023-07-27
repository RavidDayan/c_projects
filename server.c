#include <stdio.h>
#include <stdbool.h>

int boardLength(int board[3][3]){
    return sizeof(board[0])/sizeof(board[0][0]);
}

void printBoard(int board[3][3]){
    int length=boardLength(board);
    for(int i=0;i<length;i++){
        for(int j=0;j<length;j++){
            switch (board[i][j])
            {
            case 0:
                printf("__");
                break;
            case 1:
                printf("X");
                break;
            
            case 2:
                printf("O");
                break;
            }
        }
        printf("\n");
    }
}

void getPlayerInput(int *pBoard[3][3]){
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
int canBeInserted(int *pBoard[3][3],int index){
    return (*pBoard[getRow(index)][getCOL(index)]==0)?1:0;
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
void insertInput(int index,int sign,int *pBoard[3][3]){
    *pBoard[getRow(index)][getCol(index)]=sign;
}
int findWinner(int board[3][3]){
    for(int i=0;i<3;i++){
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2] && board[i][1]!=0){
            return board[i][0];
        }
    }
    for(int i=0;i<3;i++){
        if(board[0][i]==board[1][i] && board[1][i]==board[2][i] && board[1][i]!=0){
            return board[i][0];
        }
    }
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[1][1]!=0){
        return board[1][1];
    }
    if(board[0][2]==board[1][1] && board[1][1]==board[2][0] && board[1][1]!=0){
        return board[1][1];
    }
    return 0;
}
int main(){
    int board[3][3]={{0,0,0},{0,0,0},{0,0,0}};
    int *pBoard[3][3]=&board;
    enum Signs{x=1,o=2};
    enum Signs playerSign;
    int winner=0;
    int rounds=7;
    while(winner==0 || rounds<=9){
        playerSign=x;


    }
    return 0;
}