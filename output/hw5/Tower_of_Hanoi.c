#include <stdio.h>

void hanoi(int n, char src, char dest, char temp);

int main(void){
    int n = 0;

    scanf("%d",&n);
    hanoi(n,'A','C','B');
    return 0;
}

void hanoi(int n, char src, char dest, char temp){

    if(n==1){
        //printf("move disk%d from Tower %c to Tower %c\n",n,src,dest);
        printf("%d\n",n);
        return;
    }
    
    //move n-1 from A to B
    hanoi(n-1,src,temp,dest);

    //move n from A to C
    //printf("move disk%d from Tower %c to Tower %c\n",n,src,dest);
    printf("%d\n",n);
    //move n-1 from B to C
    hanoi(n-1,temp,dest,src);

}