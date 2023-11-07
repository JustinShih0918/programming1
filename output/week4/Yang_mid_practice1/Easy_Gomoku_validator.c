#include <stdio.h>
#include <string.h>

//int comparator(int a, int b, int c,int mode);
int inspect(int a[][16]);
void printAll(int a[][16]);
void judge(int a,int i);

int main(void){
    int N;
    int board[16][16];
    memset(board,0,sizeof(board));

    // int bigX = 0;
    // int bigY = 0;
    // int smallX = 0;
    // int smallY = 0;
    int hasWin = 0;
    int step = 0;

    scanf("%d",&N);
    int xy[N][2];
    memset(xy,0,sizeof(xy));
    for(int i = 0;i<N;i++){
        scanf("%d %d",&xy[i][0],&xy[i][1]);
    }



    //1 for LSC, -1 for TSC
    for(int i = 1;i<=N/2;i++){
        board[xy[2*i-2][0]][xy[2*i-2][1]]=1;
        step++;
        //printAll(board);
        hasWin = inspect(board);
        if(hasWin==1){
            printf("LSC wins at the %dth step.\n", step);
            break;
        }
        else if(hasWin==-1){
            printf("TSC wins at the %dth step.\n",step);
            break;
        }
        //printAll(board);
        board[xy[2*i-1][0]][xy[2*i-1][1]]=-1;
        step++;
        //printAll(board);
        hasWin = inspect(board);
        if(hasWin==1){
            printf("LSC wins at the %dth step.\n", step);
            break;
        }
        else if(hasWin==-1){
            printf("TSC wins at the %dth step.\n",step);
            break;
        }
        //printAll(board);
    }
    if(hasWin==0){
        printf("There's no winner.\n");
    }

    
}

int inspect(int a[][16]){
//1 for LSC
    //-1 for TSC
    int amount = 0;
    //inspect at x-direction
    for(int i = 1;i<=15;i++){
        int k = 5;
        int j = 1;
        while(j<=k&&k<=15){
            for(int h = j;h<=k;h++){
                amount+=a[i][h];

                if(amount==5){
                    return 1;
                }
                else if(amount==-5){
                    return -1;
                }
            }
            amount = 0;
            j++;
            k++;
        }
    }

    //inspect y-direction
    for(int i = 1;i<=15;i++){
        int k = 5;
        int j = 1;
        while(j<=k&&k<=15){
            for(int h = j;h<=k;h++){
                amount+=a[h][i];

                if(amount==5){
                    return 1;
                }
                else if(amount==-5){
                    return -1;
                }
            }
            amount = 0;
            j++;
            k++;
        }
    }

    //inspect left-slash
    for(int i = 1;i<=11;i++){
        for(int j= 1;j<=11;j++){
            amount = 0;
            for(int k = 0;k<=4;k++){
                amount+=a[i+k][j+k];
            }
            //printf("amount:%d\n",amount);
            if(amount==5){
                return 1;
            }
            else if(amount==-5){
                return -1;
            }

        }
    }

    //inspect right-slash
    for(int i = 15;i>=5;i--){
        for(int j= 1;j<=11;j++){
            amount = 0;
            for(int k = 0;k<=4;k++){
                amount+=a[i-k][j+k];
            }
            //printf("amount:%d\n",amount);
            if(amount==5){
                return 1;
            }
            else if(amount==-5){
                return -1;
            }
        }
    }
    return 0;
}

void printAll(int a[][16]){
    for(int i = 1;i<16;i++){
        for(int j = 1;j<16;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void judge(int a,int i){
    if(a==1){
        printf("LSC wins at the %dth step.\n", i);
    }
    else if(a==0){
        printf("TSC wins at the %dth step.\n",i);
    }
}