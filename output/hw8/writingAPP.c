#include <stdio.h>
#include <string.h>

int dfs(char a[],int n,int k);
int isP(char a[]);
int removeA(char a[],int idxToDel);
void pArr(char a[]);


int main(void){
    int n,k;
    scanf("%d %d",&n,&k);
    char word[n];  
    scanf("%s",word);
    printf(dfs(word,n,k)? "Yes\n":"No\n");
}

int dfs(char a[],int n,int k){
    if(k==0){
        //pArr(a);
        return isP(a);
    }

    for(int i = 0;i<n;i++){
        char b[n];
        strcpy(b,a);
        if(removeA(b,i)) return 1;
        if(dfs(b,n-1,k-1)) return 1;
    }
    return 0;
}

int isP(char a[]){
    int length = (int)strlen(a);
    int r = 0;
    int l = length-1;
    int answer = 1;
    while(r<length&&l>=0){
        if(a[r]==a[l]){
            r++;
            l--;
        }else{
            answer = 0;
            break;
        }
    }
    return answer;
}

int removeA(char a[],int idxToDel){
    memmove(&a[idxToDel], &a[idxToDel + 1], strlen(a) - idxToDel);
    return isP(a);
}


void pArr(char a[]){
    int length = (int)strlen(a);
    printf("%c",a[0]);
    for(int i = 1;i<length;i++){
        printf(" %c",a[i]);
    }
    printf("\n");
}