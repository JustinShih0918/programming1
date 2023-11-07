#include <stdio.h>

int main(void){
    int n;
    char letter[3];
    scanf("%c%c%c %d",&letter[0],&letter[1],&letter[2],&n);
    n = n%26;
    for(int i=0;i<3;i++){
        letter[i] = letter[i]+n;
        if(letter[i]<65){
            letter[i]+=26;
        }else if(letter[i]>90){
            letter[i]-=26;
        }
        printf("%c",letter[i]);
    }
    printf("\n");
}