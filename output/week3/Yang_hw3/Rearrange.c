#include <stdio.h>

int main(void){
    int N,M;
    scanf("%d %d",&N,&M);
    int exchange[M][2];
    int line[N];

    for(int i = 0;i<M;i++){
        scanf("%d %d",&exchange[i][0],&exchange[i][1]);
    }

    for(int i = 0;i<N;i++){
        line[i] = i+1;
    }

    for(int i = 0;i<M;i++){
        for(int j=0;j<N;j++){
            if(line[j]==exchange[i][0]){
                for(int k = 0;k<N;k++){
                    if(line[k]==exchange[i][1]){
                    line[k] = exchange[i][0];
                    break;
                    }
                }
                line[j] = exchange[i][1];
                break;
            }
        }
    }

    for(int i = 0;i<N-1;i++){
        printf("%d ",line[i]);
    }
    printf("%d\n",line[N-1]);
}