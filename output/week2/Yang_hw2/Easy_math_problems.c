#include <stdio.h>
#include <math.h>

int main(void){
    float firN;
    float secN;
    char a;
    float answer = 0;
    scanf("%f %c %f",&firN,&a,&secN);

    if(a=='+'){
        answer = firN+secN;
        printf("%.3f\n",answer);
    }
    else if(a=='-'){
        answer = firN-secN;
        printf("%.3f\n",answer);
    }
    else if(a=='/'){
        answer = (float)firN/secN;
        printf("%.3f\n",answer);
    }
    else if(a=='*'){
        answer = (float)firN*secN;
        printf("%.3f\n",answer);
    }
    
}