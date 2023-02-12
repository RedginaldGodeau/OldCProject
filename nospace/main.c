#include "src/main.h"
#include "src/funct.h"

int main(int argc, char const *argv[]) {
    
    char sentence[100];
    StrGet(sentence,100,"Donnez votre phrase a corriger : \t");
    clr();

    int i = 0,space = 0;
    while(sentence[i] != '\0') {
        if(sentence[i] == ' ') space++; else space = 0;
        if(space > 1) replace (sentence, i); else i++;
    }
    if (sentence[i] == ' ') sentence[i] = '\0';
    

    printf("\n\t%s",sentence);

    return EXIT_SUCCESS;
}


void replace (char* sentence, int place) {
    int i;
    for (i = place; sentence[i+1] != '\0'; i++) sentence[i] = sentence[i+1];
    sentence[i] = '\0';
}