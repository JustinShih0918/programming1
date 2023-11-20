#include <stdio.h>
#include <string.h>
int dm[1001][1001];
void pArr(char a[],int left,int right);
int isP(char a[],int left,int right);

int main(void){
    memset(dm,-1,sizeof(dm));
    int n,k;
    scanf("%d %d",&n,&k);
    char word[n];  
    scanf("%s",word);
    int ans = isP(word,0,n-1);
    if(ans<=k) printf("Yes\n");
    else printf("No\n");
}


int isP(char a[],int left,int right){
    if(left>=right){
        dm[left][right] = 0;
        return dm[left][right];
    }
    //recursion
    if(a[left]==a[right]) {
        dm[left][right] = isP(a,left+1,right-1);
        return dm[left][right];
    }
    else{
        if(dm[left][right]==-1){
            int dL = isP(a,left+1,right);
            int dR = isP(a,left,right-1);
            dm[left][right] = (dL>dR)?dR+1:dL+1;
            return dm[left][right];
        }
        else return dm[left][right];
        
    }
}

void pArr(char a[],int left,int right){
    printf("%c",a[left]);
    for(int i = left+1;i<=right;i++){
        printf(" %c",a[i]);
    }
    printf("\n");
}