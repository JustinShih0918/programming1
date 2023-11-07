#include <stdio.h>

int main(void){
    int x  = 1234;
    scanf("%d",&x);
    int fourthNumber = x%10;
    x = x-fourthNumber;
    int thirdNumber = x%100/10;
    x = x-x%100;
    int secondNumber = x%1000/100;
    x = x-x%1000;
    int firstNumber = x/1000;
    
    int up = firstNumber+thirdNumber;
    int down = secondNumber+fourthNumber;
    float answer = (float)up/down;
    printf("%.2f\n",answer);
    return 0;
    
}