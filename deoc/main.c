#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
    FILE *f;
    f = fopen("objet.bin","wb+");

    int nombre = 77;

    fwrite(&nombre, sizeof(int),1,f);

    fclose(f);
    return 0;
}
