#include <stdio.h>
#include <string.h>

int n;
char v[27];
char input[7];
char store[101][7];
int order[101][7];
int ans[101];



void find_order(int index){
    int times = 0;
    for(int i = 0;i<26;i++){
        for(int j = 0;j<7;j++){
            if(input[j]==v[i]){
                order[index][j] = i;
                times++;
            }
            if(times==7){
                break;
                i = 7;
            }
        }
    }
    
}

int cmp_1(int a,int b){
    if(a>b) return 1;
    else if(a<b) return -1;
    else return 0;
}

void sort_1(int index){
    char temp;
    int tempN;
    for(int i = 0;i<5;i++){
        for(int j = 0;j<5-i;j++){
            if(cmp_1(order[index][j],order[index][j+1])>0){
                temp = input[j];
                input[j] = input[j+1];
                input[j+1] = temp;

                tempN = order[index][j];
                order[index][j] = order[index][j+1];
                order[index][j+1] = tempN; 
            }
        }
    }
}
void save(int index){
    strcpy(store[index],input);
}

int cmp_2(int a,int b){
    int res = strcmp(store[a],store[b]);
    return res;
    
}

void sort_2(){
    for(int i = 0;i<n;i++){
        ans[i] = i;
    }
    for(int i = 0;i<n-1;i++){
        for(int j = 0;j<n-1-i;j++){
            if(cmp_2(ans[j],ans[j+1])>0){
                int temp = ans[j];
                ans[j] = ans[j+1];
                ans[j+1] = temp;
            }
        }
    }
}


int main(){
    scanf("%d\n",&n);
    scanf("%s\n",v);
    for(int i = 0;i<n;i++){
        scanf("%s",input);
        find_order(i);
        sort_1(i);
        save(i);
    }

    sort_2();
    printf("%s",store[ans[0]]);
    for(int i = 1;i<n;i++){
        printf(" %s",store[ans[i]]);
    }
    printf("\n");

}