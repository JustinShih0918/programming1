#include <stdio.h>

int main() {
    char b;
    scanf("%c",&b);
    if(b<=55&&b>=48) printf("I am integer");
    else if((b>=65&&b<=90)||(b>=97&&b<=122)) printf("I am an English number");

    return 0;
}
