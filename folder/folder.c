#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
    
    FILE *file;
    FILE *save;
    char ligne[300];

    int num = 0;


    file = fopen("samba.txt","rt"); // mettre t apres la a,w,r
    save = fopen("save.txt","wt");

    while (fgets(ligne,300,file)) {
        if(ligne[0] != '#') {
            fprintf(save,"%s",ligne);
        }
        if(ligne[0] == '[') num++;
    }

    printf("%d de sections",num);

    fclose(save);
    fclose(file);

    return 0;
}
