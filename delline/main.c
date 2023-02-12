#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clear(char *s) {
    for (; *s; s++) if (*s=='\n') *s='\0';
}

int main(int argc, char const *argv[]) {
    
    FILE *file;
    FILE *save;

    char line[300];
    char nom[300];

    file = fopen("fichier.txt","rt");
    save = fopen("save.txt","wt");

    fgets(nom,300,stdin);

    while (fgets(line,300,file)) {
        clear(line);
        if(strcasecmp(line, nom ) !=  0) {
            fprintf(save,"%s\n",line);
        }
    }

    fclose(file);
    fclose(save);

    remove("fichier.txt");
    rename("save.txt","fichier.txt");

    return 0;
}
