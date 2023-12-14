#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.c"

#define MAX_NAME 100

typedef int (*func_ptr)(const void*, const void*);

int N, X;
int O[3];
func_ptr cmp[3] = { price_cmp, discount_cmp, quality_cmp };

int qsort_cmp( const void* lhs, const void* rhs){
    for(int i=0; i<3; i++){
        int res = cmp[ O[i]-1 ](lhs, rhs);
        if( res != 0 ) // If not same
            return res;
    }
    // This case will not appear in Test cases;
    int str_res = strcmp( ((Item*)lhs)->name, ((Item*)rhs)->name);
    if( str_res < 0 ) return -1;
    if( str_res > 0 ) return 1;
    return 0;
}


int main(){
    int T;
    scanf("%d", &T);
    for(int cnt=1; cnt<=T; cnt++){
        scanf("%d %d %1d%1d%1d", &N, &X, &O[0], &O[1], &O[2]);

        Item* L = CreateList(N);
        char name[MAX_NAME+1];
        int P, D, Q;
        for(int i=0; i<N; i++){
            scanf("%s %d %d %d", name, &P, &D, &Q);

            AddItem(L, i, name, P, D, Q);
        }
        
        qsort( L, N, sizeof( Item ), qsort_cmp);

        printf("case %d:\n", cnt);
        for(int i=0; i<N; i++){
            int sp = L[i].price - L[i].discount;
            if( sp < X ){
                printf("%s\n", L[i].name);
                X -= sp;
            }
        }
        DeleteList(L, N);
    }
    return 0;
}