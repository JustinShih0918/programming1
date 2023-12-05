#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int n;
char key[1005];
int cnt[1005];
char person[100005];
char temp1[100005];
char temp2[100005];
char temp3[100005];
char maxSen[100001];
char maxName[100001];
const char s[6] = " ,.!?";
char *token;


int main(void){
    
    scanf("%d %s\n",&n,key);
    int klen = strlen(key);
    int max = 0;
    
    for(int i = 0;i<n;i++){
        if(fgets(person,100005,stdin)!=NULL){
            memset(temp1,'\0',sizeof(temp1));
            memset(temp2,'\0',sizeof(temp2));
            memset(temp3,'\0',sizeof(temp3));
            int len = strlen(person);
            int pos = 0;
            for(int j = 0;j<len;j++){
                if(person[j]==':') pos = j;
            }
            strncpy(temp1,person,pos);
            strcpy(temp2,&person[pos+1]);
            strcpy(person,temp1);
            strcpy(temp3,temp2);
            token = strtok(temp2,s);
            while(token!=NULL){
                int tlen = strlen(token);
                int isS = 0;
                if(tlen == klen){
                    for(int k = 0;k<tlen;k++){
                        if((key[k]==token[k])||(toupper(key[k])==token[k])||(tolower(key[k])==token[k])){
                            isS = 1;
                        }
                        else{
                            isS = 0;
                            break;
                        }
                    }
                }
                if(isS) cnt[i]++;
                token = strtok(NULL,s);
            }
        } 
        if(cnt[i]>max){
            max = cnt[i];
            strcpy(maxName,person);
            strcpy(maxSen,temp3);
        }
        
    }


    printf("%s: %s",maxName,maxSen);
}