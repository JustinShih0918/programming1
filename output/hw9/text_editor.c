#include <stdio.h>
#include <string.h>

#define MAX_SIZE 500

char content[MAX_SIZE];
char input[MAX_SIZE];
char temp[MAX_SIZE];

int main()
{

    fgets(input, MAX_SIZE, stdin);

    int len = (int)strlen(input);
    
    
    for(int i = 0,j = 0;i<len;i++){
        if(input[i]=='/'){
            switch (input[i+1])
            {
            case 'b':
                if(j-1>=0){
                    strcpy(temp,&content[j]);
                    strcpy(&content[j-1],temp);
                    j--;
                    i = i+9;
                }
                else{
                    i = i+9;
                }
                break;
            case 'n':
                strcpy(temp,content+j);
                content[j] = '\n';
                strcpy(&content[j+1],temp);
                j++;
                i = i+7;
                break;
            case 'l':
                if(j-1>=0) j--;
                i = i+4;
                break;
            case 'r':
                if(content[j]!='\0') j++;
                i = i+5;
                break;   
            default:
                strcpy(temp,content+j);
                content[j] = input[i];
                strcpy(&content[j+1],temp);
                j++;
            }
        }else if(input[i]!='\n'&&input[i]!='/'){
            strcpy(temp,content+j);
            content[j] = input[i];
            strcpy(&content[j+1],temp);
            j++;
        }
    }

    printf("%s",content);

    return 0;
}