#include <stdio.h>
#include <string.h>

unsigned long long f(long long x);
unsigned long long g(long long x);
unsigned long long a,b,c,d;
unsigned long long valF[82];
unsigned long long valG[82];

int main(void){
    memset(valF,0,sizeof(valF));
    memset(valG,0,sizeof(valG));
    long long n;
    scanf("%llu %llu %llu %llu %llu",&a,&b,&c,&d,&n);
    unsigned long long a = f(n);
    unsigned long long b = g(n);
    printf("%llu %llu\n",a,b);

}

unsigned long long f(long long x){
    if(x==0){
        return a;
    }
    else if(x==1){
        return b;
    }
    else if(x%3==0){
        if(valF[x]!=0){
            return valF[x];
        }else{
            valF[x] = f(x-1)+g(f(x/3)%x);
            return valF[x];
        }
        
    }else if(x%3!=0){
        if(valF[x]!=0){
            return valF[x];
        }else{
            valF[x] = f(x-1)+g(x-2);
            return valF[x];
        }
    }
}

unsigned long long g(long long x){
    if(x==0){
        return c;
    }
    else if(x==1){
        return d;
    }
    else if(x%5==0){
        if(valG[x]!=0){
            return valG[x];
        }else{
            valG[x] = g(x-1)+f(g(x/5)%x);
            return valG[x];
        }
    }
    else if(x%5!=0){
        if(valG[x]!=0){
            return valG[x];
        }else{
            valG[x] = g(x-1)+f(x-2);
            return valG[x];
        }
    }
}