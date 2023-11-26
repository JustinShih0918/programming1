#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int prime(int n);

int main(void){
    int n;
    scanf("%d",&n);
    int nPrime = prime(n); 
    printf("%d\n",nPrime);
}

int prime(int n){
    int t = 0;
    int target = 2;
    while(t!=n){
        int isPrime = 0;
        for(int i = 1;i<=target-1;i++){
            if(target%i==0&&i!=1) {
                isPrime = 0;
                break;
            }
            isPrime = 1;
        }
        if(isPrime==1){
            t++;
        }
        target++;
    }
    return --target;
   
}

