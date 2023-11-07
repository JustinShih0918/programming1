#include <stdio.h>
#include <math.h>

int main(void){
    int n,k;
    long long a;
    scanf("%d %d",&n,&k);
    for(int i = 1;i<=n;i++){
        a = 0;
        int length = 2*i-1;
        //printf("length:%d\n",length);
        if(i%2!=0){
            for(int j = 0;j<length;j++){
                if(j>length/2){
                    a = a/k;
                }
                else{
                    a = 1*pow(k,j);
                }

                if(j==length-1){
                    printf("%lld",a);
                }
                else{
                    printf("%lld ",a);
                }
            }
            printf("\n");
        }else if(i%2==0){
            for(int j = 0;j<length;j++){
                if(j>length/2){
                    a = a-k;
                }
                else{
                    a = 1+k*j;
                }
                if(j==length-1){
                    printf("%lld",a);
                }
                else{
                    printf("%lld ",a);
                }
            }
            printf("\n");
        }
    }
}