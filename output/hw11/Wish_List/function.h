#ifndef __FUNCTION_H__
#define __FUNCTION_H__


typedef struct _Item {
    char* name;
    int price;
    int discount;
    int quality;
} Item;

Item* CreateList(int N);
void AddItem( Item* L, int idx, char* name, int price, int discount, int quality );
void DeleteList(Item* L, int N);

int price_cmp( const void* lhs, const void* rhs );
int discount_cmp( const void* lhs, const void* rhs );
int quality_cmp( const void* lhs, const void* rhs );

#endif