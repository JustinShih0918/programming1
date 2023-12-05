#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXL 100005
#define MAXN 1005

int n;
char key[MAXN];
int cnt[MAXN];
char person[MAXL];
char tempName[MAXL];
char tempSen[MAXL];
char temp[MAXL];
char *token;
char s[6] = " ,!?.";
char ansPerson[MAXL];
char ansSen[MAXL];
int max = 0;

int main(){
    scanf("%d %s\n",&n,key);
    int klen = strlen(key);
    for(int i = 0;i<n;i++){
        if(fgets(person,MAXL,stdin)!=NULL){
            memset(tempName,'\0',sizeof(tempName));
            memset(tempSen,'\0',sizeof(tempSen));
            memset(temp,'\0',sizeof(temp));
            int len = strlen(person);
            int pos = 0;
            for(int j = 0;j<len;j++){
                if(person[j]==':'){
                    pos = j;
                    break;
                }
            }
            strncpy(tempName,person,pos);
            strcpy(tempSen,&person[pos+1]);
            strcpy(temp,tempSen);
            //printf("%s\n%s\n%s\n",tempName,tempSen,temp);
            
            token = strtok(temp,s);
            while(token!=NULL){
                int tlen = strlen(token);
                int isS = 0;
                if(tlen==klen){
                    for(int k = 0;k<tlen;k++){
                        if((token[k]==key[k])||(toupper(token[k])==key[k])||(tolower(token[k])==key[k])){
                            isS = 1;
                        }else{
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
            strcpy(ansPerson,tempName);
            strcpy(ansSen,tempSen);
            max = cnt[i];
        }
    }
    printf("%s: %s",ansPerson,ansSen);
}