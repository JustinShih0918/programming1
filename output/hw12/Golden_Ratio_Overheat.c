#include <stdio.h>
#include <string.h>

char f0[2020];
char f1[2020];
long long len[100];
int n;
long long k;

char search(int n,long long k){
    if(n==1) return f1[k];
    else if(n==0) return f0[k];

    if(k>=len[n-2]) return search(n-1,k-len[n-2]);
    else return search(n-2,k);
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%s %s",f0,f1);
        scanf("%d %lld",&n,&k);
        len[0] = strlen(f0);
        len[1] = strlen(f1);

        for(int i = 2;i<n;i++){
            len[i] = len[i-2]+len[i-1];
        }
        char ans = search(n,k);
        printf("%c\n",ans);
    }
}