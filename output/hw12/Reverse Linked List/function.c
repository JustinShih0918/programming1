#include <stdio.h>
#include <string.h>
#include "function.h"

void Push(Node** ptr_head, int x){
    Node* new = malloc(sizeof(Node));
    new->next = *ptr_head;
    new->data = x;
    *ptr_head = new;
}
void Pop(Node** ptr_head){
    if(*ptr_head==NULL) return;
    Node* delt = *ptr_head;
    *ptr_head = (*ptr_head)->next;
    free(delt);
}
void Reverse_List(Node** ptr_head){
    Node* tmp;
    Node* scan;
    Node* new_head = NULL;
    while(*ptr_head!=NULL){
        scan = *ptr_head;
        tmp = malloc(sizeof(Node));
        tmp->data = scan->data;
        tmp->next = new_head;
        new_head = tmp;
        *ptr_head = scan->next;
        free(scan);
    }
    *ptr_head = new_head;
}