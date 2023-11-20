#include <stdio.h>
#include <string.h>

void func(int index,int a[],int b[]);
void pA(int a[],int length);

int main(void){
    int N,X;
    scanf("%d %d",&N,&X);
    int a[N];
    int b[N];

    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));

    for(int i = 0;i<N;i++){
        scanf("%d",&a[i]);
    }

    int isF = 0;
    for(int i = 0;i<N;i++){
       func(i,a,b);
       if(b[i]==X&&!isF){
            printf("%d",i+1);
            isF = 1;
       }
       else if(b[i]==X&&isF){
            printf(" %d",i+1);
       }
    }
    if(isF) printf("\n");
    else printf("ouo\n");

    //pA(b,N);
}

void func(int index,int a[],int b[]){

    for(int i = index-1;i>=0;i--){
        //printf("index:%d,Val:%d\n",index,a[index]);
        if(b[i]!=0&&a[index]>a[i]){
            //printf("b:%d,a:%d\n",b[i],a[i]);
            b[index]+=(b[i]+1);
            i-=b[i];
        }else if(a[index]>a[i]){
            //printf("a:%d\n",a[i]);
            b[index]+=1;
        }else break;
    }
    //printf("final value:%d\n",b[index]);
}


void pA(int a[],int length){
    printf("%d",a[0]);
    for(int i = 1;i<length;i++){
        printf(" %d",a[i]);
    }
    printf("\n");
}