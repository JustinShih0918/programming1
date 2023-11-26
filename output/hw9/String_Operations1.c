#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void){
    char s[1000001];
    scanf("%s",s);
    int q;
    scanf("%d",&q);
    int len = strlen(s);
    //printf("q:%d\n",q);
    char alph[27];
    for(int i = 0;i<26;i++) alph[i] = i+'a';
    while(q--){
        char a,b;
        scanf("\n%c %c",&a,&b);
        //printf("a:%c,b:%c\n",a,b);
        for(int i = 0;i<26;i++){
            if(alph[i]==a) alph[i] = b;
        }
    }

    for(int i = 0;i<len;i++){
        s[i] = alph[s[i]-'a'];
    }

    for(int i = 0;i<len;i++){
        printf("%c",s[i]);
    }
    printf("\n");
    
}