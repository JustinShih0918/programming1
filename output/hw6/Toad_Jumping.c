#include <stdio.h>
#include <string.h>
int N,S,T;
int h[16];
int c[16];
int hasPass[16];
int route[16] = {0};
int totalE = 0;
int totalS = 0;

void pA(int a[],int mode);
void jump(int cur,int end,int step);
int cost(int jump);
int abs(int a);

int main(void){
    scanf("%d %d %d",&N,&S,&T);
    
    hasPass[0] = 1;
    for(int i = 1;i<=N;i++){
        hasPass[i] = 0;
    }

    h[0] = 0;
    for(int i = 1;i<=N;i++){
        scanf("%d",&h[i]);
    }

    c[0] = 0;
    for(int i = 1;i<=N;i++){
        scanf("%d",&c[i]);
    }
    route[0] = S;
    hasPass[S] = 1;
    jump(S,T,1);

    printf("%d %d\n",totalE,totalS);
}

void jump(int cur,int end,int step){

    if(cur==end){
        step--;
        int tempCost =  cost(step);
        // printf("An end step:%d val:%d\n",step,tempCost);
        // pA(route,0);
        // pA(hasPass,1);
        if(tempCost==totalE){
            //printf("there is a change\n");
            if(totalS<step){
                totalE = tempCost;
                totalS = step;
            }   
        }else if(tempCost>totalE){
            totalE = tempCost;
            totalS = step;
        }
        hasPass[route[step]] = 0;
        route[step] = 0;
        
        return;
    }
    
    for(int i = -1;i<=N;i++){
        //printf("A new jump i:%d step:%d\n",i,step);
        if(i>=1&&c[i]==c[cur]&&hasPass[i]!=1){
            hasPass[route[step]] = 0;
            route[step] = 0;
            route[step] = i;
            hasPass[i] = 1;
            // pA(route,0);
            // pA(hasPass,1);
            jump(i,end,step+1);
        }else if(i==0&&cur+1<=N&&hasPass[cur+1]!=1){
            hasPass[route[step]] = 0;
            route[step] = 0;
            route[step] = cur+1;
            hasPass[cur+1] = 1;
            // pA(route,0);
            // pA(hasPass,1);
            jump(cur+1,end,step+1);
        }else if(i==-1&&cur-1>0&&hasPass[cur-1]!=1){
            hasPass[route[step]] = 0;
            route[step] = 0;
            route[step] = cur-1;
            hasPass[cur-1] = 1;
            // pA(route,0);
            // pA(hasPass,1);
            jump(cur-1,end,step+1);
        }else continue;
    }
        
    
    hasPass[route[step]] = 0;
    route[step] = 0;
    // pA(route,0);
    // pA(hasPass,1);
}

int cost(int jump){
    int energy = 0;

    for(int i = 1;i<=jump;i++){
        //printf("%d %d\n",route[i],route[i-1]);
        energy+=abs(route[i]-route[i-1])*abs(h[route[i]]-h[route[i-1]]);
    }

    return energy;
}

int abs(int a){
    if(a<0) return -a;
    else return a;
}

void pA(int a[],int mode){
    if(mode==0){
        printf("route:");
        for(int i = 0;i<N+1;i++){
        printf("%d ",a[i]);
        }
        printf("\n");
    }else if(mode==1){
        printf("hasPass:");
        for(int i = 1;i<N+1;i++){
        printf("%d ",a[i]);
        }
        printf("\n");
    }
}