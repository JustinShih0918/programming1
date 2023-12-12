#include "function.h"
#include <stdio.h>
#include <stdlib.h>


Table* createTable(){
    Table *table  = malloc(sizeof(Table));
    scanf("%d",&table->tableSize);
    table->guest = NULL;
    table->leaveTime = 0;
    return table;
}
Guest* createGuest(){
    Guest *guest = malloc(sizeof(guest));
    char *name = (char *)malloc(sizeof(char));
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
            Guest *temp = table[i]->guest;
            table[i]->guest = NULL;
            table[i]->leaveTime = 0;
            return temp;
        }
    }
    return NULL;
}
int assignTable(Table **table, int tableCount, int currentTime, Guest *guest){
    for(int i =0;i<tableCount;i++){
        if(table[i]->guest==NULL&&table[i]->tableSize>=guest->groupSize){
            table[i]->guest = guest;
            table[i]->leaveTime = guest->diningTime+currentTime;
            return 1;
        }
    }
    return 0;
}