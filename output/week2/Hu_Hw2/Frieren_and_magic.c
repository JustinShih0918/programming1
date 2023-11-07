#include <stdio.h>

int main(void){
    int x;
    scanf("%d",&x);
    double year_d = (double)x/365;
    float year_f = (float)x/365;
    long long second = (long long)x*86400;
    printf("%.6f %.6f %lld\n",year_d,year_f,second);
}