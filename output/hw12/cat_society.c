#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char jobs[9] = {'l','d','m','a','w','k','n','e'};

typedef struct{
    char* name;
    int job;
    int age;
}Cat;

void addCat(Cat*l,int i){
    char* name = malloc(sizeof(char)*40);
    scanf("%s",name);
    l[i].name = name;
    char* job = malloc(sizeof(char)*20);
    scanf("%s",job);
    for(int j = 0;j<9;j++){
        if(job[0]==jobs[j]){
            l[i].job = j;
            break;
        }
    }
    free(job);
    scanf("%d",&l[i].age);
}

int cmp(const void* x,const void* y){
    Cat a = *(Cat*)x;
    Cat b = *(Cat*)y;

    if(a.job>b.job) return -1;
    else if(a.job<b.job) return 1;
    else{
        if(a.job==3){
            if(a.age>b.age) return 1;
            else if(a.age<b.age) return -1;
            else return strcmp(a.name,b.name);
        }else{
            if(a.age<b.age) return 1;
            else if(a.age>b.age) return -1;
            else return strcmp(a.name,b.name);
        }
    }

}


int main(){
    int N,M;
    while(scanf("%d %d",&N,&M)!=EOF){
        Cat* clist = malloc(sizeof(Cat)*N);
        for(int i = 0;i<N;i++) addCat(clist,i);

        qsort(clist,N,sizeof(Cat),cmp);

        if(M>N) M = N;
        for(int i = 0;i<M;i++){
            printf("%s\n",clist[i].name);
        }

        for(int i = 0;i<N;i++){
            free(clist[i].name);
        }
        free(clist);
    }
}