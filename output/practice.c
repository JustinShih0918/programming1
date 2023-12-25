#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(x,y) ((x)>(y)?(x):(y))
int N;
long long price[100000];

long long recursion(int x,int hold){
    if(x>=N) return 0;
    if(!hold){
        long long buy = recursion(x+1,1)-price[x];
        long long not_buy = recursion(x+1,0);
        return max(buy,not_buy);
    }
    else{
        long long sell = recursion(x+1,0)+price[x];
        long long not_sell = recursion(x+1,1);
        return max(sell,not_sell);
    }
}

long long record(){
    long long hold = -2e9;
    long long nothold = 0;
    for(int i = 0;i<N;i++){
        long now_hold = max(hold,nothold-price[i]);
        long now_nothold = max(nothold,hold+price[i]);
        hold = now_hold;
        nothold = now_nothold;
    }
    return max(hold,nothold);
}

long long greed(){
    long long p = 0;
    for(int i = 1;i<N;i++){
        if(price[i]>price[i-1]) p+=price[i]-price[i-1];
    }
    return p;
}

int main(){
    scanf("%d",&N);
    for(int i = 0;i<N;i++){
        scanf("%d",&price[i]);
    }
    printf("%lld\n",greed());
}