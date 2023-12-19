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
    if(*ptr_head==NULL) return;
    Node *head;
    Node *tmp,*tail = NULL;
    head = *ptr_head;
    while(head->next!=NULL){
        tmp = head->next;
        head->next = tail;
        tail = head;
        head = tmp;
    }
    head->next = tail;
    *ptr_head = head;
}