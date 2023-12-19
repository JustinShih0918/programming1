#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char jobs[] = {'l','d','m','a','w','k','n','e','\0'};
int n,m;


typedef struct Cat{
    char *name;
    int job;
    int age;
}Cat;

Cat* clist[10000];


Cat* creatCat(){
    Cat* cat = malloc(sizeof(Cat));
    char* name = malloc(sizeof(char)*30);
    char* job = malloc(sizeof(char)*10);
    scanf("%s",name);
    scanf("%s",job);
    for(int i = 0;i<9;i++){
        if(job[0]==jobs[i]){
            cat->job = i;
            break;
        }
    }
    free(job);
    scanf("%d",&cat->age);
    cat->name = name;
    return cat;
}

int cmp(int a,int b){
    if(clist[a]->job<clist[b]->job) return 1;
    else if(clist[a]->job>clist[b]->job) return -1;
    else{
        if(clist[a]->job==3){
            if(clist[a]->age<clist[b]->age) return -1;
            else if(clist[a]->age>clist[b]->age) return 1;
            else return strcmp(clist[a]->name,clist[b]->name);
            
        }else{
            if(clist[a]->age<clist[b]->age) return 1;
            else if(clist[a]->age>clist[b]->age) return -1;
            else return strcmp(clist[a]->name,clist[b]->name);
        }
    }
}

int cmp_1(const void** a,const void** b){
    Cat* A = *(Cat**)a;
    Cat* B = *(Cat**)b;
    if(A->job<B->job) return 1;
    else if(A->job>B->job) return -1;
    else{
        if(A->job==3){
            if(A->age<B->age) return -1;
            else if(A->age>B->age) return 1;
            else return strcmp(A->name,B->name);
            
        }else{
            if(A->age<B->age) return 1;
            else if(A->age>B->age) return -1;
            else return strcmp(A->name,B->name);
        }
    }
}

void printCat(int i){
    printf("%s %d %d\n",clist[i]->name,clist[i]->job,clist[i]->age);
}

int main(){
    
    while(scanf("%d %d",&n,&m)!=EOF){
        
        for(int i = 0;i<n;i++) clist[i] = creatCat();
        qsort(clist,n,sizeof(Cat*),cmp_1);
        if(m>n) m = n;
        for(int i = 0;i<m;i++){
            printf("%s\n",clist[i]->name);
        }
        

        for(int i = 0;i<n;i++){
            free(clist[i]->name);
            free(clist[i]);
        }
    }
}