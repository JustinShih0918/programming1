#include <stdio.h>
#include <string.h>

int Num[10];
int solution[10];

int N, M, K;

//use the bubble sort algorithm to sort an integer array: from small to large
void bubble_sort(int ap[], int n) {
    int i, j, temp;

    for (i=0; i<n-1; i++) {
        for (j=0; j<n-1-i; j++) {
            if (ap[j]>ap[j + 1]) {
                temp=ap[j];
                ap[j]=ap[j+1];
                ap[j+1]=temp;
            }
        }
    }
}

//A recursive function you need to implement:
//  int p: the current position to consider
//  int LB: the left bound of the range of possible choices for the current position
//  int RB: the right bound of the range of possible choices for the current position
void comb(int p, int LB, int RB,int times) {
    //basic step
    if(times==0){
        if(K==0){
            for(int i = M-1;i>=0;i--){
                printf("%d ",solution[i]);
            }
            printf("\n");
            return;
        }else return;
    }

    //recursive step
    //do the first one
    int temp = -1;
    for(int i = p;i<=RB;i++){
        if(Num[i]!=temp){
            temp = Num[i];
            solution[times-1] = Num[i];
            K-=Num[i];
            // for(int i = 0;i<10;i++){
            //     printf("%d ",solution[i]);
            // }
            // printf("\n K:%d times:%d\n",K,times);
            comb(i+1,LB,RB,times-1);
            solution[times-1] = 0;
            K+=Num[i];
        }
    }
}

int main(void) {
    int T;
    int i;

    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &N, &M, &K);
        for (i=0; i<N; i++) {
            scanf("%d", &Num[i]);
        }
        
        memset(solution,0,sizeof(solution));
        bubble_sort(Num, N);

        //... your code here ...
        comb(0,0,N-1,M);
    }

    return 0;
}
