#include <stdio.h>
#include "function.c"
#define TABLE_COUNT 50
#define GUEST_COUNT 50
#define OPEN_TIME 660
#define CLOSE_TIME 900

Table *table[TABLE_COUNT];
Guest *guest[GUEST_COUNT];
int tableCount, guestCount;
int currentGuest = 0;

void tableStatus(int time) {
    printf("%02d:%02d (%d) -> table: |", time/60, time%60, time);
    for (int i=0; i<tableCount; i++) {
        if (table[i]->guest) printf("%s(%dmin)", table[i]->guest->guestName, table[i]->leaveTime-time);
        printf("|");
    }
    printf("\n");
}

int main() {
    scanf("%d", &tableCount);
    for (int i=0; i<tableCount; i++){
        table[i] = createTable();
        
    }
    scanf("%d", &guestCount);
    for (int i=0; i<guestCount; i++) {
        guest[i] = createGuest();
    }
    for (int i=OPEN_TIME; i<=CLOSE_TIME; i++) {
        while (1) {
            Guest *leave = checkLeave(table, tableCount, i);
            if (!leave) break;
            printf("%02d:%02d (%d) -> %s: leave\n", i/60, i%60, i, leave->guestName);
        }
        while (currentGuest < guestCount && guest[currentGuest]->arriveTime <= i) {
            int success = assignTable(table, tableCount, i, guest[currentGuest]);
            if (!success) break;
            printf("%02d:%02d (%d) -> %s: enter\n", i/60, i%60, i, guest[currentGuest]->guestName);
            currentGuest++;
        }
        if (i % 60 == 0) tableStatus(i);
    }
}