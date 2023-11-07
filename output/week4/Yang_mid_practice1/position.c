#include <stdio.h>
#include <string.h>

int main(void){
    char s[1000001];
    char finding[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','\0'};
    scanf("%s",s);
    int length = (int)strlen(s);
    
    for(int i = 0;i<52;i++){
        int isExist = -1;
        int index[1000001];
        memset(index,-1,sizeof(index));
        int a = 0;
        for(int j = 0;j<length;j++){
            if(s[j]==finding[i]){
                isExist = 1;
                index[a] = j;
                a++;
            }
        }
        if(isExist==1){
            int b = 0;
            printf("%c: ",finding[i]);
            while (index[b]!=-1&b<1000000)
            {   
                int checkbox = b+1;
                if(index[checkbox] == -1){
                    printf("%d\n",index[b]);
                }
                else {
                    printf("%d ",index[b]);
                }
                b++;
            }
            
        }

    }
}