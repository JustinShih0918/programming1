#include "function.h"  /* Include the header (not strictly necessary here) */
#include <stdio.h>
#include <string.h>
#include <math.h>

int solver(int **ptr, int *sum, char *s){
    
    int n = 0;
    int i = 0;
    while (s[i]!='\0')
    {
        //printf("at ith:%d, the char is %c\n",i,s[i]);
        if(s[i]=='-'&&s[i+1]<=57&&s[i+1]>=48){
            //printf("Inside the - section, at ith:%d, the char is %c and i+1 is %c\n",i,s[i],s[i+1]);
            *sum = 0;
            int localN = 0;
            int start = i+1;
            i+=2;
            n++;
            while(s[i]<=57&&s[i]>=48){
                //printf("in behind there is %c\n",s[i]);
                localN++;
                i++;
            }
            i--;
            int end = i;
            //printf("start at %d,end at %d,localN:%d\n",start,end,localN);
            for(;start<=end;start++){
                int power = (int)pow(10,localN);
                *sum += power*(s[start]-'0');
                //printf("power:%d,s:%d",power,(s[start]-'0'));
                localN--; 
            }
            *sum = -*sum;
            //printf("sum:%d\n",*sum);
            **ptr = *sum;
            //printf("ptr:%d\n",**ptr);
            ptr++;
        }else if(s[i]<=57&&s[i]>=48){
            //printf("inside + section, at ith:%d, the char is %c and i+1 is %c\n",i,s[i],s[i+1]);
            *sum = 0;
            int start = i;
            int localN = 0;
            n++;
            i++;
            while(s[i]<=57&&s[i]>=48){
                //printf("in behind there is %c\n",s[i]);
                i++;
                localN++;
            }
            i--;
            int end = i;
            //printf("start at %d,end at %d,localN:%d\n",start,end,localN);
            for(;start<=end;start++){
                *sum += pow(10,localN)*(s[start]-'0');
                localN--; 
            }
            //printf("sum:%d\n",*sum);
            **ptr = *sum;
            //printf("ptr:%d\n",**ptr);
            ptr++;
        }
        i++;
    }
    *sum = 0;
    ptr-=(n);
    for(int j = 0;j<n;j++){
        *sum += **(ptr+j);
        //printf("at %dth,sum = %d,ptr=%d\n",j,*sum,**(ptr+j));
    }
    
    return n;
}
