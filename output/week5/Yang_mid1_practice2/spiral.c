#include <stdio.h>
#include <string.h>



int main(void){
    int T;
    scanf("%d",&T);
    int times = 1;
    while(times<=T){
        int N;
        scanf("%d",&N);
        char sp[N][N];
        int length = N;
        memset(sp,' ',sizeof(sp));
        int nowX = 0;
        int nowY = 0;
        
        while(N>0){
            //go right
            for(int i = 0;i<N;i++){
                sp[nowY][i+nowX] = '#';
            }
            nowX = nowX+N-1;
            N--;
        

            
            //go down
            nowY++;
            for(int i = 0;i<N;i++){
                sp[nowY+i][nowX] = '#';
            }
            nowY = nowY+N-1;
            N--;
            

            //go left
            for(int i = N;i>0;i--){
                sp[nowY][nowX-i] = '#';
            }
            nowX = nowX-(N);
            N--;
            
            //go up
            for(int i = N;i>0;i--){
                sp[nowY-i][nowX] = '#';
            }
            nowY = nowY-(N);
            N--;
            nowX++;
            
        }
        for(int i = 0;i<length;i++){
                for(int j = 0;j<length;j++){
                    printf("%c",sp[i][j]);
                }
                printf("\n");
        }

        times++;
    }
}

