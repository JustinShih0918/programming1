#include <stdio.h>
#include <string.h>

int main(void){
    char input[1001];
    char checkF[1001]="";
    char checkB[1001]="";
    int amount = 0;
    scanf("%s",input);

    int length = strlen(input);
    int boolen = 1;
    for(int i = 0;i<length;i++){
        for(int j = length;j>i+2;j--){
            for(int k = i;k<j;k++){
                checkF[k] = input[k];
                checkB[j-1-k+i] = checkF[k];
            }
            for(int h = i;h<j;h++){
                boolen = 1;
                if(checkB[h]==checkF[h]){
                    boolen = boolen*1;
                }
                else{
                    boolen = boolen*-1;
                    break;
                }
            }
            (boolen>0)?(amount++):(amount=amount);
        }
    }
    printf("%d\n",amount);
}