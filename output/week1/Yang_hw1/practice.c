#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n,k;
#define MAXN 1005
#define MAXLEN 305
char d[MAXN][MAXN] = {'\0'};
int cnt[MAXN] = {0};
int len[MAXN] = {0};
int ans[MAXN];



int cmp_1(int a,int b){
    if(cnt[a]<cnt[b]) return 1;
    else if(cnt[a]>cnt[b]) return -1;
    else{
        if(len[a]<len[b]) return 1;
        else if(len[a]>len[b]) return -1;
        else {
            int res = strcmp(d[a],d[b]);
            if(res>0) return -1;
            else if(res<0) return 1;
            else return 0;
        }
    }
}
void bubble_sort_1(){
    for(int i = 0;i<n-1;i++){
        for(int j = 0;j<n-1-i;j++){
            if(cmp_1(ans[j],ans[j+1])>0){
                int temp = ans[j];
                ans[j] = ans[j+1];
                ans[j+1] = temp;
            }
        }
    }
}

int cmp_2(int a,int b){
    if(len[a]>len[b]) return 1;
    else if(len[a]<len[b]) return -1;
    else return strcmp(d[a],d[b]);
}

void bubble_sort_2(){
    for(int i = 0;i<k-1;i++){
        for(int j = 0;j<k-1-i;j++){
            if(cmp_2(ans[j],ans[j+1])>0){
                int temp = ans[j];
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
    bubble_sort_1();
    bubble_sort_2();
}


void hex_to_dec(char* input,int n){

    for(int i = 0,j=0;input[j]!='\0';i = j+1){
        char hex[MAXLEN] = {'\0'};
        char dec[MAXLEN] = {'\0'};
        int  num = 0;
        j = i;
        while(input[j]!='|'&&input[j]!='\0') j++;
        strncpy(hex,input+i,j-i);
        sscanf(hex,"%x",&num);
        sprintf(dec,"%d",num);
        strcat(d[n],dec);
        //printf("%s\n",d[n]);
    }
    len[n] = strlen(d[n]);
    for(int i = 0;i<len[n];i++){
        if(d[n][i]=='7') cnt[n]++;
    }
}

int main() {
    scanf("%d %d",&n,&k);
    char input[255];
    for(int i = 0;i<n;i++){
        scanf("%s",input);
        hex_to_dec(input,i);
    }
    find_ans();
    for(int i = 0;i<k;i++){
        printf("%s\n",d[ans[i]]);
    }

    
    return 0;
}
