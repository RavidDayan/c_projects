#include <stdio.h>
#include <stdbool.h>

int getRow(int cell){
    return (cell-1)/3;
}
int getCol(int cell){
        return (cell-1)%3;
}
int canBeInserted(int board[3][3],int index){
    return (board[getRow(index)][getCol(index)]==0)?1:0;
}
int isCellLegal(int index){
    return (index<1 || index>9)?0:1;
}

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
                printf(" _ ");
                break;
            case 1:
                printf(" X ");
                break;
            
            case 2:
                printf(" O ");
                break;
            }
        }
        printf("\n");
    }
}

int getPlayerInput(int board[3][3]){
    int input;
    do{
        printf("please enter a number between 1 to 9 :");
        scanf("%d",&input);
        if(isCellLegal(input)==0){
            printf("invalid cell number, please try again\n");
        }
        else{
            if (canBeInserted(board,input)==0){
                    printf("cell is taken, please try again\n");
                }
        }
    }while(isCellLegal(input)==0 || canBeInserted(board,input)==0);
    return input;
}


void insertInput(int index,int sign,int board[3][3]){
    board[getRow(index)][getCol(index)]=sign;
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
void switchPLayer(int *pPlayerSign){
    if(*pPlayerSign==1){
        *pPlayerSign=2;
    }
    else{
        *pPlayerSign=1;
    }
}
int main(){
    int board[3][3]={{0,0,0},{0,0,0},{0,0,0}};
    int playerSign=1;
    int playerInput;
    int winner=0;
    int rounds=0;
    while(winner==0 && rounds<=9){
        rounds++;
        switchPLayer(&playerSign);
        playerInput=getPlayerInput(board);
        insertInput(playerInput,playerSign,board);
        winner=findWinner(board);
        printBoard(board);
    }

    if(winner==0){
        printf("The game ended in a tie\n");
    }
    else{
        printf("The winner is %d\n",winner);
    }
    return 0;
}