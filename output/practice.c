#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int row[50][50];
int col[50][50];
char grid[50][50];
int N,M;

int check(){
    for(int i = 0;i<N;i++){
        int cnt = 0;
        int idx = 0;
        for(int j = 0;j<=M;j++){
            if(grid[i][j]=='o') cnt++;
            else if(cnt>0){
                if(idx==row[i][0]) return 0;
                if(cnt!=row[i][++idx]) return 0;
                cnt = 0;
            }
        }
        if(idx!=row[i][0]) return 0;
    }

    for(int i = 0;i<M;i++){
        int cnt = 0;
        int idx = 0;
        for(int j = 0;j<=N;j++){
            if(grid[j][i]=='o') cnt++;
            else if(cnt>0){
                if(idx==col[i][0]) return 0;
                if(cnt!=col[i][++idx]) return 0;
                cnt = 0;
            }
        }
        if(idx!=col[i][0]) return 0;
    }

    return 1;

}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        memset(row,0,sizeof(row));
        memset(col,0,sizeof(col));
        memset(grid,'\0',sizeof(grid));
        scanf("%d %d",&N,&M);
        
        for(int i = 0;i<N;i++){
            scanf("%d",&row[i][0]);
            for(int j = 1;j<=row[i][0];j++){
                scanf("%d",&row[i][j]);
            }
        }

        for(int i = 0;i<M;i++){
            scanf("%d",&col[i][0]);
            for(int j = 1;j<=col[i][0];j++){
                scanf("%d",&col[i][j]);
            }
        }

        for(int i = 0;i<N;i++){
            scanf("%s",grid[i]);
        }

        printf(check()?"Yes\n":"No\n");
    }
}