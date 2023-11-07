#include <stdio.h>
#include <string.h>
int k;
long long Sier(int k);

int main(void){
    scanf("%d",&k);
    long long answer = Sier(k);
    printf("%lld\n",answer);
}

long long Sier(int k){
    if(k==1){
        return 1;
    }else if(k==0){
        return 0;
    }

    return 8*Sier(k-1)+1;
}