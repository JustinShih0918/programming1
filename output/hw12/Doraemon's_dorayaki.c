#include <stdio.h>
#define max(x,y) (((x)>(y))?(x):(y))
int n;
int price[100000];


long long Recursion(int x,int hold){
    if(x>=n) return 0;
    if(!hold){
        long long to_buy = Recursion(x+1,1)-price[x];
        long long not_buy = Recursion(x+1,0);
        return max(to_buy,not_buy);
    }else{
        long long to_sell = Recursion(x+1,0) + price[x];
        long long not_sell = Recursion(x+1,1);
        return max(to_sell,not_sell);
    }
}

long long Memorization(){
    long long hold = -2e9,nothold = 0;
    for(int i = 0;i<n;i++){
        long long now_hold = max(hold,nothold-price[i]);
        long long now_nothold = max(nothold,hold+price[i]);
        hold = now_hold;
        nothold = now_nothold;
    }
    return nothold;
}

long long greed(){
    long long ans = 0;
    for(int i =1;i<n;i++){
        ans += max(0,price[i]-price[i-1]);
    }
    return ans;
}

int main(){
    scanf("%d",&n);
    for(int i = 0;i<n;i++) scanf("%d",&price[i]);
     printf("%lld\n",greed());
}