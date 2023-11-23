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
    if((r-l)>1){
        for(int i = l;i<r;i++){
            if(solve(l,i)&&solve(i+1,r)){
                flag = 1;
                break;
            }
        }
        if(solve(l+1,r-1)&&s[l]=='('&&s[r]==')') flag = 1;
    }
    else if(s[l]=='('&&s[r]==')') flag = 1;
    else if(l==r&&s[r]==' ') flag =1;
    // End 
    record[l][r] = flag;
    return flag;
}

int main () {
    int T;
    scanf("%d", &T);
    while (T--) {
        for (int i = 0;i < MAXN; ++i)
            for (int j = 0;j < MAXN; ++j)
                record[i][j] = -1;
        scanf("%s", s);
        int flag = solve(0, strlen(s)-1);
        printf(flag ? "Yes\n" : "No\n");
    }
    return 0;
}