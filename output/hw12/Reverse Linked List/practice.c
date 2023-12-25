#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"

void Push(Node** ptr_head,int x){
    Node* new = malloc(sizeof(Node));
    new->data = x;
    new->next = *ptr_head;
    *ptr_head = new;
}
void Pop(Node** ptr_head){
    if(*ptr_head==NULL) return;
    Node *temp = *ptr_head;
    *ptr_head = (*ptr_head)->next;
    free(temp);
}
void Reverse_List(Node** ptr_head){
    if(*ptr_head==NULL) return;
    Node* newhead;
    Node* tail = NULL;
    Node* temp = NULL;
    newhead = *ptr_head;
    while(newhead->next!=NULL){
        temp = newhead->next;
        newhead->next = tail;
        tail = newhead;
        newhead = temp;
    }
    newhead->next = tail;
    *ptr_head = newhead;
}