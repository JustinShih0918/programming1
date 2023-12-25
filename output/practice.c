#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N,M;
int grid[20][20];
int x[5] = {1,-1,0,0,0};
int y[5] = {0,0,1,-1,0};
int isG;

void flip(int i,int j){
    for(int k = 0;k<5;k++){
        grid[i+x[k]][j+y[k]] = !grid[i+x[k]][j+y[k]];
    }
}

int check(){
    for(int i = 1;i<=N;i++){
        for(int j = 1;j<=M;j++){
            if(grid[i][j]!=grid[1][1]) return 0;
        }
    }
    return 1;
}

void solve(int x,int y,int times,int goal){
    if(goal==times){
        isG = check();
        return;
    }

    if(x==N+1||isG) return;
    
    flip(x,y);
    if(y<M) solve(x,y+1,times+1,goal);
    else solve(x+1,1,times+1,goal);

    flip(x,y);
    if(y<M) solve(x,y+1,times,goal);
    else solve(x+1,1,times,goal);
    
    return;
}


int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&N,&M);
        char tmp;
        for(int i = 1;i<=N;i++){
            for(int j= 1;j<=M;j++){
                scanf(" %c",&tmp);
                if(tmp=='b') grid[i][j] = 0;
                else if(tmp=='w') grid[i][j] = 1;
            }
        }

        int goal = N*M;
        for(int i = 0;i<=goal;i++){
            solve(1,1,0,i);
            if(isG){
                printf("%d\n",i);
                break;
            }
        }

        if(isG==0) printf("oops\n");
    }
}