#include <stdio.h>
#include <string.h>

int main(void){
    char input[100003];
    while(gets(input)){
        int length = strlen(input);
        if(input[0]=='#'){
            printf("%s\n",input);
        }
        else if(input[length-1]=='{'){
            for(int i = 0;i<length;i++){
                if(input[i]==';'){
                    input[i] = ' ';
                }else{
                    break;
                }
            }
            printf("%s\n",input);
        }
        else if(input[length-1]=='}'){
            for(int i = 0;i<length;i++){
                if(input[i]==';'){
                    input[i] = ' ';
                }else if(input[i]!='}'&&input[i]!=';'){
                    input[length] = ';';
                    length++;
                    break;
                }
            }
            printf("%s\n",input);
        }
        else{
            for(int i = 0;i<length-1;i++){
                if(input[i]==';'){
                    input[i] = ' ';
                }else{
                    break;
                }
            }
            if(input[length-1]==';'){
                input[length-1] = ' ';
            }else{
                input[length] = ';';
                length++;
            }
            printf("%s\n",input);
        }
        memset(input,0,sizeof(input));
    }
}
