#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){
    char alph[26];
    char s[1000001];
    scanf("%s",s);
    for(int i = 0;i<26;i++) alph[i] = i+'a';
    int q;
    int i,j;
    scanf("%d",&q);
    for(i = 0;i<q;i++){
        char a,b;
        scanf("\n%c %c",&a,&b);
        for(j = 0;j<26;j++) {
            if(alph[j]==a) alph[j] = b;
        }
    }
    int len = strlen(s);
    for(i = 0;i<len;i++){
        s[i] = alph[s[i]-'a'];
    }
    printf("%s\n",s);
}