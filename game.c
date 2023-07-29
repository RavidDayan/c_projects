#include <stdio.h>
#include <stdbool.h>

int getRow(int cell){
    return (cell-1)/3;
}
int getCol(int cell){
        return (cell-1)%3;
}
int canBeInserted(int (*pBoard)[3][3],int index){
    return ((*pBoard)[getRow(index)][getCol(index)]==0)?1:0;
}
int isCellLegal(int index){
    return (index<1 || index>9)?0:1;
}
void printBoard(int (*pBoard)[3][3]){   
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            switch ((*pBoard)[i][j])
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
int getPlayerInput(int (*pBoard)[3][3]){
    int input=0;
    do{
        printf("please enter a number between 1 to 9 :");
        scanf("%d",&input);
        if(isCellLegal(input)==0){
            printf("invalid cell number, please try again\n");
        }
        else{
            if (canBeInserted(pBoard,input)==0){
                    printf("cell is taken, please try again\n");
                }
        }
    }while(isCellLegal(input)==0 || canBeInserted(pBoard,input)==0);
    return input;
}
void insertInput(int index,int sign,int (*pBoard)[3][3]){
    (*pBoard)[getRow(index)][getCol(index)]=sign;
}
int findWinner(int (*pBoard)[3][3]){
    for(int i=0;i<3;i++){
        if((*pBoard)[i][0]==(*pBoard)[i][1] && (*pBoard)[i][1]==(*pBoard)[i][2] && (*pBoard)[i][1]!=0){
            return (*pBoard)[i][0];
        }
    }
    for(int i=0;i<3;i++){
        if((*pBoard)[0][i]==(*pBoard)[1][i] && (*pBoard)[1][i]==(*pBoard)[2][i] && (*pBoard)[1][i]!=0){
            return (*pBoard)[i][0];
        }
    }
    if((*pBoard)[0][0]==(*pBoard)[1][1] && (*pBoard)[1][1]==(*pBoard)[2][2] && (*pBoard)[1][1]!=0){
        return (*pBoard)[1][1];
    }
    if((*pBoard)[0][2]==(*pBoard)[1][1] && (*pBoard)[1][1]==(*pBoard)[2][0] && (*pBoard)[1][1]!=0){
        return (*pBoard)[1][1];
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
    int (*pBoard)[3][3]=&board;
    int playerSign=1;
    int playerInput;
    int winner=0;
    int rounds=0;
    while(winner==0 && rounds<=9){
        rounds++;
        switchPLayer(&playerSign);
        playerInput=getPlayerInput(pBoard);
        insertInput(playerInput,playerSign,pBoard);
        winner=findWinner(pBoard);
        printBoard(pBoard);
    }

    if(winner==0){
        printf("The game ended in a tie\n");
    }
    else{
        printf("The winner is %d\n",winner);
    }
    return 0;
}