#include <stdio.h>
#include <string.h>
#define min(x,y) (x)<(y)?(x):(y);

char *preprocess (char a[],int n, char b[]);
int manacher(char s[],int n);

int Expand(char a[],int length,int left,int right);


int main(void){
    char input[10001]="";
    while (scanf("%s",input)!=EOF)
    {
        int length = (int)strlen(input);
        //printf("Length:%d\n",length);
        int max = 1;
        for(int i = 0;i<length;i++){
            //printf("i:%d\n",i);
            int k1 = Expand(input,length,i-1,i+1);
            int k2 = Expand(input,length,i,i+1);

            int length1 = k1*2+1;
            int length2 = k2*2;

            if(length1>max) max = length1;
            if(length2>max) max = length2;
            
        }
        printf("%d\n",max);
    }
}


// int length = (int)strlen(input);
        // int n = length*2+1;
        // char s[n];
        // preprocess(input,length,s);
        // int answer = manacher(s,n);     
        // printf("%d\n",answer);   

int Expand(char a[],int length,int left,int right){
    int amount = 0;
    while(left>=0&&right<length){
        if(a[left]==a[right]){
            //printf("%c,%c\n",a[left],a[right]);
            left--;
            right++;
            amount++;
            //printf("left:%d,right:%d,amount:%d\n",left,right,amount);
        }else{
            break;
        }
    }
    return amount;
}

int manacher(char s[],int n){
    int p[n];
    p[0] = 0;
    int maxP = 0;
    int r = 0;
    int c = 0;

    for(int i = 1;i<n;i++){
        if(i<r){
            int j = c-(i-c);
            p[i] = min(p[j],r-i);
        }else{
            p[i] = 0;
        }

        int left = i-p[i]-1;
        int right = i+p[i]+1;

        while(s[left]==s[right]&&left>=0&&right<n){
            left--;
            right++;
            p[i]++;
        }
        right = i+p[i];

        if(right>r){
            r= right;
            c=i;
        }

        if(maxP<p[i]) maxP=p[i];
        
        //printf("%d ",p[i]);
    }
    return maxP;
}


char *preprocess(char a[],int n,char b[]){
    int i = 0;
    int j = 0;
    while(i<n){
        b[j++] = '|';
        b[j++] = a[i++];
    }
    b[j++] = '|';
}

//https://writings.sh/post/algorithm-longest-palindromic-substring