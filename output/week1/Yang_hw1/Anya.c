#include <stdio.h>

int main(void){
    int P, A, B, C, D;//1,5,10,50
    int amount = 0;
    scanf("%d%d%d%d%d",&P,&A,&B,&C,&D);
    while (P>=50&&D>0)
    {
        P-=50;
        D--;
        amount++;
    }
    while (P>=10&&C>0)
    {
        P-=10;
        C--;
        amount++;
    }
    while (P>=5&&B>0)
    {
        P-=5;
        B--;
        amount++;
    }
    while (P>=1&&A>0)
    {
        P-=1;
        A--;
        amount++;
    }
    if(P==0){
        printf("%d\n",amount);
    }
    else{
        printf("%d\n",-1);
    }
}


