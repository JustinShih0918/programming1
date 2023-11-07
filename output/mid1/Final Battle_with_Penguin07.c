#include <stdio.h>
#include <string.h>
long long N,M,K,Q;
void insert(long long b[N+1][M+1],long long x1,long long y1,long long x2,long long y2,long long c);


int main(void){
    scanf("%lld %lld %lld %lld",&N,&M,&K,&Q);
    long long A[N+1][M+1];
    memset(A,0,sizeof(A));

    for(int i = 1;i<=N;i++){
        for(int j = 1;j<=M;j++){
            scanf("%lld",&A[i][j]);
        }
    }

    long long B[N+1][M+1];
    memset(B,0,sizeof(B));
    

    for(int i = 1;i<=N;i++){
        for(int j = 1;j<=M;j++){
            insert(B,i,j,i,j,A[i][j]);
        }
    }

    for(int t = 1;t<=K;t++){
        long long x1,y1,x2,y2,z;
        scanf("%lld %lld %lld %lld %lld",&x1,&y1,&x2,&y2,&z);
        insert(B,x1,y1,x2,y2,z);
    }

    for(int i = 0;i<=N;i++){
        for(int j = 0;j<=M;j++){
            printf("%lld ",B[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(int i = 1;i<=N;i++){
        for(int j = 1;j<=M;j++){
            //printf("ij:%d left:%d up:%d minus:%d ",B[i][j],B[i][j-1],B[i-1][j],B[i-1][j-1]);
            B[i][j] += B[i-1][j]+B[i][j-1]-B[i-1][j-1];
            //printf("result:%d\n",B[i][j]);
        }   
    }

    for(int i = 1;i<=N;i++){
        for(int j = 1;j<=M;j++){
            if(j!=M){
                printf("%lld ",B[i][j]);
            }else printf("%lld\n",B[i][j]);
        }
    }

    for(int t = 1;t<=Q;t++){
        long long query = 0;
        long long x1,y1,x2,y2;
        scanf("%lld %lld %lld %lld",&x1,&y1,&x2,&y2);
        for(int i = x1;i<=x2;i++){
            for(int j = y1;j<=y2;j++){
                printf("query:%lld +:%lld\n",query,B[i][j]);
                query += B[i][j];
            }
        }
        printf("%lld\n",query);
    }
    


}

void insert(long long b[N+1][M+1],long long x1,long long y1,long long x2,long long y2,long long c){
    b[x1][y1] += c;
    if(x2+1<=N&&y2+1<=M){
        b[x2+1][y2+1] += c;
    }
    if(y2+1<=M){
        b[x1][y2+1] -= c;
    }
    if(x2+1<=N){
        b[x2+1][y1] -= c; 

    }
    //printf("x:%d y:%d %d %d %d %d\n",x1,y1,b[x1][y1],b[x2+1][y2+1],b[x1][y2+1],b[x2+1][y1]);
}
