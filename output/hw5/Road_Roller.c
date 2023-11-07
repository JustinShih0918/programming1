#include <stdio.h>
#include <string.h>
int N,M;
int findDirection(int a[N+2][M+2],int curX,int curY); //find the biggest number of the surrounding (four direction)
int comparator(int right,int left,int up,int down); // compare four number
void showArray(int a[N+2][M+2]); // just to show the array

int main(void){
    scanf("%d %d",&N,&M);
    int A[N+2][M+2]; // add a circle of 0 out side the road, so that it won't goes out of the boundry
    memset(A,0,sizeof(A));
    for(int i = 1;i<=N;i++){
        for(int j = 1;j<=M;j++){
            scanf("%d",&A[i][j]);
        }
    }

    //Direction definitation: -1 for stop, 1 for right, 2 for left, 3 for up, 4 for down
    int nowX = 1; //record which row I am now
    int nowY = 1; //record which column I am now
    int nowD = findDirection(A,nowX,nowY); //record the direction now
    long long val = A[nowX][nowY]; //record the bumpy value I had pass through
    A[nowX][nowY] = 0; //set the current position's value 0, so it won't be calculate twice
    int tempVal = 0; //record the first value I have met, so I can judge if I have to change my direction 

    while(nowD!=-1){
        switch (nowD)
        {
            case 1:
                val+=A[nowX][++nowY]; //add the current position's value to total val
                tempVal = A[nowX][nowY]; //record the first value I met
                A[nowX][nowY] = 0; //set current position as 0
                while (++nowY<=M) //while I am still in the boundry
                {   
                        if(A[nowX][nowY]<=tempVal){
                            val += A[nowX][nowY];
                            A[nowX][nowY] = 0;
                        }else{ //if I met value that bigger then tempVal, change direction
                            val += A[nowX][nowY];
                            A[nowX][nowY] = 0;
                            break;
                        }
                    
                    
                }
                if(nowY>M) nowY--;
                nowD = findDirection(A,nowX,nowY); //find new direction
                break;
            case 2:
                val+=A[nowX][--nowY];
                tempVal = A[nowX][nowY];
                A[nowX][nowY] = 0;
                while(--nowY>=1){
                        if(A[nowX][nowY]<=tempVal){
                        val += A[nowX][nowY];
                        A[nowX][nowY] = 0;
                        }else{
                            val += A[nowX][nowY];
                            A[nowX][nowY] = 0;
                            break;
                        }
                    
                    
                }
                if(nowY<1) nowY++;
                nowD = findDirection(A,nowX,nowY);
                break;
            case 3:
                val+=A[--nowX][nowY];
                tempVal = A[nowX][nowY];
                A[nowX][nowY] = 0;
                while(--nowX>=1){
                        if(A[nowX][nowY]<=tempVal){
                            val += A[nowX][nowY];
                            A[nowX][nowY] = 0;
                        }else{
                            val += A[nowX][nowY];
                            A[nowX][nowY] = 0;
                            break;
                        }
                }
                if(nowX<1) nowX++;
                nowD = findDirection(A,nowX,nowY);
                break;
            case 4:
                val+=A[++nowX][nowY];
                tempVal = A[nowX][nowY];
                A[nowX][nowY] = 0;
                while(++nowX<=N){
                        if(A[nowX][nowY]<=tempVal){
                            val += A[nowX][nowY];
                            A[nowX][nowY] = 0;
                        }else{
                            val += A[nowX][nowY];
                            A[nowX][nowY] = 0;
                            break;
                        }
                    
                    
                }
                if(nowX>N) nowX--;
                nowD = findDirection(A,nowX,nowY);
                break;
        }

    }

    int isClean = 0; //determine if the array are all 0
    for(int i = 1;i<=N;i++){
        for(int j = 1;j<=M;j++){
            if(A[i][j]!=0){//if there exist something != 0, break the loop
                isClean = -1; 
                i = N+1;
                break;
            }
        }
    }
    printf("%lld\n",val);
    if(isClean==0) printf("Road Roller Da!!\n");

    
}   


int findDirection(int a[N+2][M+2],int curX,int curY){ //determine the direction
    int right = a[curX][curY+1];
    int left = a[curX][curY-1];
    int up = a[curX-1][curY];
    int down = a[curX+1][curY]; 
    int max = comparator(right,left,up,down); //get the biggest number
    
    if(right==left&&left==up&&up==down&&down==0) return -1; //if the surounding are all 0, means I have to stop

    if(max==right) return 1;
    else if(max==left) return 2;
    else if(max==up) return 3;
    else if(max==down) return 4;
    else return -1;
}


int comparator(int right,int left,int up,int down){
    int t;
     if (right > left)
    {
        t = right;
        right = left;
        left = t;
    }
    if (left > up)
    {
        t = left;
        left = up;
        up = t;
    }
    if (up > down)
    {
        t = up;
        up = down;
        down = t;
    }
    
    return down;
    
}

void showArray(int a[N+2][M+2]){
    for(int i = 0;i<N+2;i++){
        for(int j = 0;j<M+2;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}