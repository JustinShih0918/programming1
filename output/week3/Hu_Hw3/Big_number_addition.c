#include <stdio.h>
#include <math.h>
#include <string.h>

int main(void){
    int A,B;
    char arrA[201] = "\0";
    char arrB[201] = "\0";
    
    
    scanf("%d\n%s\n%d\n%s",&A,arrA,&B,arrB);

    int nA[A];
    int nB[B];

    //reverse the char array
    char temp = 0;
    for(int i =0;i<A/2;i++){
        temp = arrA[i];
        arrA[i] = arrA[A-1-i];
        arrA[A-1-i] = temp;
    }
    for(int i =0;i<B/2;i++){
        temp = arrB[i];
        arrB[i] = arrB[B-1-i];
        arrB[B-1-i] = temp;
    }

    // for(int i = 0;i<201;i++){
    //     printf("%c",arrA[i]);
    // }
    // printf("\n");
    // for(int i = 0;i<201;i++){
    //     printf("%c",arrB[i]);
    // }
    // printf("\n");

    //convert char array to integer array
    for(int i = 0;i<A;i++){
        nA[i] = arrA[i]-'0';
    }
    for(int i = 0;i<B;i++){
        nB[i] = arrB[i]-'0';
    }

    //finding the bigger length of two array
    int bigger;
    int whoBig;
    (A>B)?(bigger=A):(bigger=B);

    if(A>B){
        whoBig=0;
    }else if(A<B){
        whoBig=1;
    }
    else{
        whoBig = 2;
    }

    //doing adding
    int answer[102] = {0};
    for(int i = 0;i<bigger;i++){
        if(whoBig==0){
            if(i>=B){
                answer[i]+=nA[i];
                if(answer[i]>=10){
                    answer[i]-=10;
                    answer[i+1]+=1;
                }
            }else{
                answer[i] += nA[i]+nB[i];
                if(answer[i]>=10){
                    answer[i]-=10;
                    answer[i+1]+=1;
                }
            }
        }else if(whoBig==1){
            if(i>=A){
                answer[i]+=nB[i];
                if(answer[i]>=10){
                    answer[i]-=10;
                    answer[i+1]+=1;
                }
            }else{
                answer[i] += nA[i]+nB[i];
                if(answer[i]>=10){
                    answer[i]-=10;
                    answer[i+1]+=1;
                }
            }
        }else if(whoBig==2){
            answer[i] += nA[i]+nB[i];
                if(answer[i]>=10){
                    answer[i]-=10;
                    answer[i+1]+=1;
                }
        }    
        //printf("now is round %d, and answer[i] = %d,answer[i+1] = %d\n",i,answer[i],answer[i+1]);
    }

    //Reveres the answer array
    int temp1 = 0;
    if(answer[bigger]==0){
        for(int i = 0;i<(bigger)/2;i++){
        temp1 = answer[i];
        answer[i] = answer[bigger-1-i];
        answer[bigger-1-i] = temp1;
        }

        for(int i = 0;i<bigger;i++){
        printf("%d",answer[i]);
        }
    }else if(answer[bigger]==1){
        for(int i = 0;i<(bigger+1)/2;i++){
        temp1 = answer[i];
        answer[i] = answer[bigger-i];
        answer[bigger-i] = temp1;
        }

        for(int i = 0;i<bigger+1;i++){
        printf("%d",answer[i]);
        }
    }
}

