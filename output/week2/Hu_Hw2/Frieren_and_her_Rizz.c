#include <stdio.h>

int main(void){
    int a[6];
    int decode;
    int answer = 65;
    int c = 0;
    scanf("%d",&decode);
    for(int i=5;i>=0;i--,c++){
        a[i] = decode%10;
        decode = decode/10;
    }

    answer = answer+a[0]*32+a[1]*16+a[2]*8+a[3]*4+a[4]*2+a[5]*1-1;
    printf("%c\n",answer);
}