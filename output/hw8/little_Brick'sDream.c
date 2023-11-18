#include <stdio.h>
#include <string.h>

void func(int x);
void pA(int a[],int length);

int main(void){
    int N,X;
    scanf("%d %d",&N,&X);
    int a[N];
    int b[N];
    int c[N];
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(b));

    for(int i = 0;i<N;i++){
        scanf("%d",&a[i]);
    }

    int n = 0;
    for(int i = N-1;i>=0;i--){
        for(int j = i-1;j>=0;j--){
            if(a[i]>a[j]) b[i]++;
            else break;
        }
        if(b[i]==X){
            c[n] = i+1;
            n++;
        }
    }

    if(c[0]==0) printf("ouo\n");
    else{
        for(int i = n-1;i>=1;i--){
            printf("%d ",c[i]);
        }
        printf("%d\n",c[0]);
    }
}

void pA(int a[],int length){
    printf("%d",a[0]);
    for(int i = 1;i<length;i++){
        printf(" %d",a[i]);
    }
    printf("\n");
}