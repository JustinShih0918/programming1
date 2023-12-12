#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;
char v[27];
char a[101][7];
char order[27];
char *rank[101];

int cmp_1(const void* x,const void* y){
    return order[*(const char*)x-'a'] - order[*(const char*)y-'a'];
}

int cmp_2(const void*x,const void*y){
    return strcmp(*(const char**)x,*(const char**)y);
}

int main(){
    scanf("%d",&n);
    scanf("%s",v);
    for(int i = 0;i<26;i++){
        order[v[i]-'a'] = i;
    }
    for(int i = 0;i<n;i++){
        scanf("%s",a[i]);
        qsort(a[i],6,sizeof(char),cmp_1);
        rank[i] = a[i];
    }
    qsort(rank,n,sizeof(char*),cmp_2);
    printf("%s",rank[0]);
    for(int i = 1;i<n;i++){
        printf(" %s",rank[i]);
    }
    printf("\n");
}