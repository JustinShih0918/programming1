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
    Node* tmp = malloc(sizeof(Node));
    tmp = *ptr_head;
    *ptr_head = tmp->next;
    free(tmp);
}
void Reverse_List(Node** ptr_head){
    if(*ptr_head==NULL) return;
    Node* head;
    Node* tail = NULL;
    Node* tmp = NULL;
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