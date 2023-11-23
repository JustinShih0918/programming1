#include <stdio.h>
#include <string.h>
int r,c,k,m;
int dom[102][102];
int rec[102][102];
int x[4] = {-1,1,0,0};
int y[4] = {0,0,1,-1};
void pA(int a[102][102]);
int main(void){
    memset(dom,-1,sizeof(dom));
    memset(rec,0,sizeof(rec));

    scanf("%d %d %d %d",&r,&c,&k,&m);
    for(int i = 1;i<=r;i++){
        for(int j = 1;j<=c;j++){
            scanf("%d",&dom[i][j]);
        }
    }
    while(m--){
        for(int i = 1;i<=r;i++){
            for(int j = 1;j<=c;j++){
                int val = 0;
                if(dom[i][j]!=-1) val = dom[i][j]/k;
                //else if(dom[i][j]%k!=0&&dom[i][j]!=-1) val = dom[i][j]/k+1;
                for(int d = 0;d<4;d++){
                    if(dom[i+x[d]][j+y[d]]!=-1){
                        rec[i+x[d]][j+y[d]]+= val;
                        rec[i][j] -= val;
                    }
                }
            }
        }

        for(int i = 1;i<=r;i++){
            for(int j = 1;j<=c;j++){
                dom[i][j] += rec[i][j];
            }
        }
        memset(rec,0,sizeof(rec));
    }
    pA(dom);
}

void pA(int a[102][102]){
    for(int i = 1;i<=r;i++){
        printf("%d",a[i][1]);
        for(int j = 2;j<=c;j++){
            printf(" %d",a[i][j]);
        }
        printf("\n");
    }
}