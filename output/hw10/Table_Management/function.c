#include "function.h"
#include <stdio.h>
#include <stdlib.h>


Table* createTable(){
    Table *table = malloc(sizeof(Table));
    int size;
    scanf("%d",&size);
    table->tableSize = size;
    table->leaveTime = 0;
    table->guest = NULL;
    return table;
}
Guest* createGuest(){
    Guest *guest = malloc(sizeof(Guest));
    char *name = (char *)malloc(sizeof(char)*15);
    scanf("%s",name);
    guest->guestName = name;
    scanf("%d",&guest->groupSize);
    scanf("%d",&guest->arriveTime);
    scanf("%d",&guest->diningTime);
    
    return guest;
}
Guest* checkLeave(Table **table, int tableCount, int currentTime){
    for(int i = 0;i<tableCount;i++){
        if(table[i]->leaveTime==currentTime){
            Guest *guest = table[i]->guest;
            table[i]->guest = NULL;
            table[i]->leaveTime =0;
            return guest;
        }
    }
    return NULL;
}
int assignTable(Table **table, int tableCount, int currentTime, Guest *guest){
    for(int i = 0;i<tableCount;i++){
        if((table[i]->guest==NULL)&&((table[i]->tableSize)>=(guest->groupSize))){
            table[i]->guest = guest;
            table[i]->leaveTime = (guest->diningTime)+currentTime;
            return 1;
        }
    }
    return 0;
}
