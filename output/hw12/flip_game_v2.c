#include <stdio.h>
#include <string.h>

int N,M;
int grid[20][20];
int MIN;
int cnt;
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
    for(int k = 0;k<5;k++){
        grid[i+x[k]][j+y[k]] = !grid[i+x[k]][j+y[k]];
    }
}


void dfs(int id){
    if(MIN>cnt&&check()) MIN = cnt;
    if(id==N*M) return;

    //no flip
    dfs(id+1);
    if(cnt+1>=MIN) return;
    //flip
    flip(id/M+1,id%M+1);
    cnt++;
    dfs(id+1);
    flip(id/M+1,id%M+1);
    cnt--;
}

void solve(){
    MIN = 7122;
    cnt = 0;
    dfs(0);
    if(MIN==7122) printf("oops\n");
    else printf("%d\n",MIN);
}


int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&N,&M);
        char tmp;
        for(int i = 1;i<=N;i++){
            for(int j = 1;j<=M;j++){
                scanf(" %c",&tmp);
                if(tmp=='w') grid[i][j] = 1;
                else if(tmp=='b') grid[i][j] = 0;
            }
        }

        solve();
    }
}