#include <stdio.h>
#include <string.h>

int N,M;
int grid[20][20];
int isG;
int x[5] = {1,-1,0,0,0};
int y[5] = {0,0,1,-1,0};

int check(){
    for(int i = 1;i<=N;i++){
        for(int j = 1;j<=M;j++){
            if(grid[i][j]!=grid[1][1]) return 0;
        }
    }
    return 1;
}

void flip(int i,int j){
    for(int a = 0;a<5;a++){
        grid[i+x[a]][j+y[a]] = !grid[i+x[a]][j+y[a]];
    }
}


void solve(int x,int y,int times,int goal){
    if(times==goal){
        isG = check();
        return;
    }
    if(isG||x==N+1) return;
    
    flip(x,y);
    if(y<M) solve(x,y+1,times+1,goal);
    else solve(x+1,1,times+1,goal);

    flip(x,y);
    if(y<M) solve(x,y+1,times,goal);
    else solve(x+1,1,times,goal);
    return;    
}

void printArr(){
    for(int i = 1;i<=N;i++){
        for(int j = 1;j<=M;j++){
            printf("%d ",grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&N,&M);
        isG = 0;
        char temp;
        for(int i = 1;i<=N;i++){
            for(int j = 1;j<=M;j++){
                scanf(" %c",&temp);
                if(temp=='w') grid[i][j] = 1;
                else if(temp=='b') grid[i][j] = 0;
            }
        }
        int step = N*M;
        for(int i = 0;i<=step;i++){
            solve(1,1,0,i);
            if(isG){
                printf("%d\n",i);
                break;
            }
        }
        if(isG==0) printf("oops\n");
    }
}