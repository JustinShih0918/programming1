#include <stdio.h>

int main(void){
    int h1;
    int h2;
    int m1;
    int m2;
    int sleepTime = 0;
    scanf("%d:%d\n%d:%d",&h1,&m1,&h2,&m2);

    //method 1
    sleepTime = (h2-h1)*60+m2-m1;
    if(sleepTime<0){
        sleepTime+=24*60;
    }
    
    //method 2
    // if(h1<h2){
    //   sleepTime = (h2-h1)*60+(m2-m1);
    // }
    // else if(h1>h2){
    //     sleepTime = (24+(h2-h1))*60 + m2-m1;
    // }
    // else if(h1==h2&m2<m1){
    //     sleepTime = 24*60+(m2-m1);
    // }
    // else{
    //     sleepTime = (h2-h1)*60+m2-m1;
    // }
    printf("%d\n",sleepTime);
}

