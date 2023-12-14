#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"


Item* CreateList(int N){
    Item *list = (Item*)malloc(sizeof(Item)*N);
    return list;
}
void AddItem( Item* L, int idx, char* name, int price, int discount, int quality ){
    L[idx].name = (char*)malloc(sizeof(char)*(strlen(name)+1));
    strcpy(L[idx].name,name);
    L[idx].price = price;
    L[idx].discount = discount;
    L[idx].quality = quality;
}

void DeleteList(Item* L, int N){
    for(int i = 0;i<N;i++){
        free(L[i].name);
    }
    free(L);
    
}

int price_cmp( const void* lhs, const void* rhs ){
    const Item* l = (const Item*)lhs;
    const Item* r = (const Item*)rhs;
    int sellingL = l->price-l->discount;
    int sellingR = r->price-r->discount;
    if(sellingL>sellingR) return 1;
    else if(sellingL<sellingR) return -1;
    else return 0;
}
int discount_cmp( const void* lhs, const void* rhs ){
    const Item* l = (const Item*)lhs;
    const Item* r = (const Item*)rhs;
    if(l->discount>r->discount) return -1;
    else if(l->discount<r->discount) return 1;
    else return 0;
}
int quality_cmp( const void* lhs, const void* rhs ){
    const Item* l = (const Item*)lhs;
    const Item* r = (const Item*)rhs;
    if(l->quality>r->quality) return -1;
    else if(l->quality<r->quality) return 1;
    else return 0;
}