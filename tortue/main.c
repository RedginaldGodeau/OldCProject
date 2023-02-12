#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define gotoxy(x,y) printf("\033[%d;%dH", (y), (x))

int main(int argc, char const *argv[]) {
    
    FILE * f;
    f = fopen("fichier.txt","rt");

    char line[300];
    int x = 0, y = 0;

    while (fgets(line,300,f)) {
        clear(line);
        if(line[0] != '#') {
            
            switch (line[0]) {
                case 'H': {
                    y--;
                    break;
                }
                case 'B': {
                    y++;

                    break;
                }
                case 'G': {
                    x--;

                    break;
                }
                case 'D': {
                    x++;

                    break;
                }
            }
            
            gotoxy(x,y);
            printf("#");

        }
    }


    return 0;
}
