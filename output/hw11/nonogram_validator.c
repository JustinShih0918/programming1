#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char grid[50][50];
int row[50][50];
int col[50][50];
int N,M,T;

int solve(){
    for(int i = 0;i<N;i++){
        int cnt = 0;
        int a = 0;
        for(int j = 0;j<=M;j++){
            if(grid[i][j]=='o') cnt++;
            else if(cnt>0){
                if(a==row[i][0]){
                    return 0;
                }
                    
                if(cnt!=row[i][++a]){
                    return 0;
                }
                cnt = 0;
            }
        }
        if(a!=row[i][0]){
            return 0;
        }
    }
    //check col
    for(int i = 0;i<M;i++){
        int cnt = 0;
        int a = 0;
        for(int j = 0;j<=N;j++){
            if(grid[j][i]=='o') cnt++;
            else if(cnt>0){
                if(a==col[i][0]){
                    return 0;
                }
                if(cnt!=col[i][++a]){
                    return 0;
                }
                cnt = 0;
            }
        }
        if(a!=col[i][0]){
            return 0;
        }
    }
    return 1;
}
int main(){
    scanf("%d",&T);
   
    while(T--){
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
        memset(grid,'\0',sizeof(grid));
        for(int i = 0;i<N;i++){
            scanf("%s",grid[i]);
        }
        
        printf(solve()?"Yes\n":"No\n");
    }
}