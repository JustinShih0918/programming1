#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char d[1005][1005] = {'\0'};
int cnt[1005] = {0};
int order[1005] = {0};
int n;
int ans[1005] = {0};

int cmp(int a,int b){
    if(cnt[a]<cnt[b]) return 1;
    else if(cnt[a]>cnt[b]) return -1;
    else {
        if(order[a]<order[b]) return 1;
        else if(order[a]>order[b]) return -1;
        else{
            int lenA = strlen(d[a]);
            int lenB = strlen(d[b]);
            if(lenA<lenB) return 1;
            else if(lenA>lenB) return -1;
            else return -strcmp(d[a],d[b]);
        }
    }
}

void bubble_sort(){
    for(int i = 0;i<n-1;i++){
        for(int j = 0;j<n-1-i;j++){
            if(cmp(ans[j],ans[j+1])>0){
                int temp  = ans[j];
                ans[j] = ans[j+1];
                ans[j+1] = temp;
            }
        }
    }
}

void find_ans(){
    for(int i = 0;i<n;i++){
        ans[i] = i;
    }

    bubble_sort();
}

int main(void){
    scanf("%d",&n);
    for(int i =0;i<n;i++){
        scanf("%s",d[i]);
        int len = (int)strlen(d[i]);
        for(int j = 0;j<len;j++){
            if(d[i][j]=='7'){
                cnt[i] = 1;
                order[i] = len-j;
                break;
            }
        }
    }
    find_ans();

    for(int i = 0;i<n;i++){
        printf("%s\n",d[ans[i]]);
    }


}