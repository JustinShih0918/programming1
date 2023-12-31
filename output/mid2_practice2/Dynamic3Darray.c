#include "function.h"
#include <stdio.h>

unsigned*** new_3d_array(unsigned n,unsigned m,unsigned k){
    unsigned ***ln;
    ln = (unsigned ***)malloc(sizeof(unsigned**)*n);
    unsigned **lm;
    lm= (unsigned **)malloc(sizeof(unsigned*)*n*m);
    unsigned *lk ;
    lk = (unsigned *)malloc(sizeof(unsigned)*n*m*k);

    unsigned i,j;

    for(i = 0;i<n;i++){
        ln[i] = lm+i*m;
        for(j = 0;j<m;j++){
            lm[i*m+j] = lk + (i*m+j)*k;
        }
    }

    return ln;
}

void delete_3d_array(unsigned ***arr){
    free(arr[0][0]);
    free(arr[0]);
    free(arr);
}
