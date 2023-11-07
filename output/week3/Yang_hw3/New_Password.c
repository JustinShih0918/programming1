#include <stdio.h>

int main(void){
    char con[27];
    char ori[4];
    scanf("%s\n%s",con,ori);

    for(int i = 0;i<3;i++){
        if(ori[i]<='Z'&&ori[i]>='A'){
            ori[i] = con[ori[i]-65];
        }else{
            ori[i] = con[ori[i]-97];
            ori[i] += 32;
        }
        printf("%c",ori[i]);
    }
    printf("\n");

}