#include "funct.h"

void purger(void) {char c; while((c=getchar()) != '\n' && c != EOF);}
void scan_int(int* v) {
    scanf("%d",&v);
    purger();
}

void StrGet (char* c, int maxChar, const char* msg) {
    printf(msg);
    fgets(c,maxChar,stdin);

    int i = 0;
    for(i=0; c[i] != '\0'; i++) {if(c[i] == '\n') c[i] = '\0';}
    clr();
}