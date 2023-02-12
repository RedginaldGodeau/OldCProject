#include <stdlib.h>
#include <stdio.h>
#include <string.h>


char _strpos[300];
void strpos (char text[],char dest[], int pos) {
    int i = pos, d = 0;
    dest[0] = '\0';

    for(i = pos; text[i] != ']'; i++) {
        dest[d]=text[i];
        d++;
    }
    dest[d]='\0';  
}


int main(int argc, char const *argv[]) {

    int _linecat = 0;
    int _linecom = 0;
    int _linesec = 0;

    char line[300];
    char dest[300];
    FILE * f;

    f = fopen("samba.txt","rt");

    while (fgets(line,300,f)) {
        if(line[0] == '[') {
            if(_linesec > 0) {
                printf("Nom : %s \n",dest);
                printf("Nombre de ligne : %d \n",_linecat);
                printf("Nombre de commentaire : %d \n",_linecom);
                printf("#######################\n");
            }

            strpos(line,dest,1);
            _linecat = 0;
            _linecom = 0;
            _linesec++;
        }

        if(line[0] == '#') {
            _linecom++;
        } else {
            _linecat++;
        }
    }

    printf("Nom : %s \n",dest);
    printf("Nombre de ligne : %d \n",_linecat);
    printf("Nombre de commentaire : %d \n",_linecom);
    printf("#######################\n");

    printf("Sections : %d",_linesec);

    return 0;
}
