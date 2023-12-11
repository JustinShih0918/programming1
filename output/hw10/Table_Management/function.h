#ifndef __FUNCTION_H__
#define __FUNCTION_H__

typedef struct {
    char *guestName;
    int groupSize;
    int arriveTime;
    int diningTime;
} Guest;

typedef struct {
    int tableSize;
    int leaveTime;
    Guest *guest;
} Table;

Table* createTable();
Guest* createGuest();
Guest* checkLeave(Table **table, int tableCount, int currentTime);
int assignTable(Table **table, int tableCount, int currentTime, Guest *guest);

#endif