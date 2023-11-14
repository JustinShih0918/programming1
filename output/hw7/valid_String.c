#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXN 505 

int record[MAXN][MAXN];
char s[MAXN];

int solve(int l, int r) {
    // return 1 if s[l, r] is valid, 0 otherwise.
    if (record[l][r] != -1) return record[l][r]; // If the substring is computed, return it immediately.
    int flag = 0; // store your answer for this state in flag.
    // [TODO] Implement your codes here.

    // Noticed that you only need to store the result in "flag".
    
    // End 
    record[l][r] = flag;
    return flag;
}

int main () {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%s", s);
        int length = strlen(s);
        int count = 0;
        int flag = 0;
        for(int i = 0;i<length;i++){
            if(s[i]=='(') count++;
            else if(s[i]==')') count--;

            if(count<0){
                flag = 0;
                break;
            }
        }
        if(count==0) flag = 1;
        //int flag = solve(0, strlen(s)-1);
        printf(flag ? "Yes\n" : "No\n");
    }
    return 0;
}

//https://medium.com/spotthedifference/valid-parentheses-5169134512f2