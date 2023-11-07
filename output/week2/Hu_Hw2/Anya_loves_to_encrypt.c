#include <stdio.h>

int main(void){
    char a[6] = "";
    scanf("%s",&a);
    for(int ai = 0;ai<5;ai++){
        switch (a[ai])
        {
        case 'a':
            a[ai] = 'Z';
            break;
        case 'b':
            a[ai] = 'Y';
            break;
        case 'c':
            a[ai] = 'X';
            break;
        case 'd':
            a[ai] = 'W';
            break;
        case 'e':
            a[ai] = 'V';
            break;
        case 'f':
            a[ai] = 'U';
            break;
        case 'g':
            a[ai] = 'T';
            break;
        case 'h':
            a[ai] = 'S';
            break;
        case 'i':
            a[ai] = 'R';
            break;
        case 'j':
            a[ai] = 'Q';
            break;
        case 'k':
            a[ai] = 'P';
            break;
        case 'l':
            a[ai] = 'O';
            break;
        case 'm':
            a[ai] = 'N';
            break;
        case 'n':
            a[ai] = 'M';
            break;
        case 'o':
            a[ai] = 'L';
            break;
        case 'p':
            a[ai] = 'K';
            break;
        case 'q':
            a[ai] = 'J';
            break;
        case 'r':
            a[ai] = 'I';
            break;
        case 's':
            a[ai] = 'H';
            break;
        case 't':
            a[ai] = 'G';
            break;
        case 'u':
            a[ai] = 'F';
            break;
        case 'v':
            a[ai] = 'E';
            break;
        case 'w':
            a[ai] = 'D';
            break;
        case 'x':
            a[ai] = 'C';
            break;
        case 'y':
            a[ai] = 'B';
            break;
        case 'z':
            a[ai] = 'A';
            break;
        }
    }
    printf("%s\n",a);


}