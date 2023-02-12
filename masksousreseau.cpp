#include <stdio.h>
#include <stdlib.h> 
#include <conio.h>
#include <string.h>

#define maxchar 10

int exposant (int exp) {
    int p = 1;
    for(int i = 0; i < exp; i++) {
        p *= 10;
    }
    return p;
}

int getmasknumber (int i,int lenght,char array[]) {
    int realnumber = 0;
    for(int b = i-lenght; b < i; b++) {
        realnumber += ('0' - array[b]) * exposant (b-i-lenght);
        printf("%d \n", realnumber);
        printf("%c",array[b]);
    }
}


int main() {

    char mask[maxchar],key[maxchar];
    int i;

    printf("Masque de sous-reseau \n");
    fgets(mask,maxchar,stdin);
    int masklenght,numlenght = 0;

    int nummask = 0;
    int numkey = 0;

    for(i = 0; mask[i] != '\0'; i++) {
        if(mask[i] == '.') {
           nummask = getmasknumber (i,masklenght,mask);
           masklenght = 0;
        } else masklenght++;
    }




    return 0;
}
