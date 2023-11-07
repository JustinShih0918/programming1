#include <stdio.h>
#define ll long long

int main(void){
    int N,M;
    scanf("%d %d",&N,&M);
    ll A[N+1];
    ll B[N+1];
    A[0] = 0;
    B[0] = 0;
    for(int i = 1;i<=N;i++){
        scanf("%lld",&A[i]);
    }

    for(int i = 1;i<=N;i++){
        B[i] = A[i]-A[i-1];
    }

    
    for(int i =0;i<M;i++){
        int l,r,x;
        scanf("%d %d %d",&l,&r,&x);
        B[l] += x;
        B[r+1] -= x;
    }

    for(int i = 1;i<=N;i++){
        B[i] += B[i-1];
        if(i==N){
            printf("%lld\n",B[i]);
        }
        else{
            printf("%lld ",B[i]);
        }
    }
}
//https://walkonnet.com/archives/462481
