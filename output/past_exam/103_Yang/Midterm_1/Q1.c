#include <stdio.h>
#include <ctype.h>



int main(void){
    int times = 1;
    char ch;
    char pres1 = "";
    char pres2;
    char pres3;
    int length1 = 1;
    int length2 = 1;
    while((ch=toupper(getchar()))!='\n'){
        printf("times:%d now ch:%c\n",times,ch);
        if(pres1!=ch){
            pres2=ch;
            while(pres2==ch){
                pres3 = toupper(getchar());
                printf("current pres3:%c\n",pres3);
                if(pres2 == ch){
                    length2++;
                    printf("Do length2,current ch:%c\n",ch);
                }
                else{
                    printf("length1:%d length2:%d\n",length1,length2);
                    printf("pres1:%c pres2:%c\n",pres1,pres2);
                    (length2>length1)?(length1 = length2,pres1 = pres2,length2=1):(length2=1);
                    break;
                }
            }
        }else{
            length1++;
            printf("Do length1 ++\n");
        }
        times++;
    }
    printf("%d\n",length1);
}