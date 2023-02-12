#include "src/main.h"
#include "src/funct.h"

int main(int argc, char const *argv[]) {
    FILE* mainFile; OpenFile (&mainFile ,"./res/storage.owl");

    int selection = 0 ,action = 0,  max = 0,page = 1,maxpage = 1;
    bool ex = false;

    while(!ex) {
        while (1) {
            clr();
            mainScreen (mainFile,selection,action,page,&max,&maxpage);
            int keypress = 0;
            switch(keypress = getch()) {
                // PAGES
                case 'd' : page = (maxpage >= page+1 ? page+1 : 1 ); selection=0; break; 
                case 'q' : page = (1 <= page-1 ? page-1 : maxpage); selection=0; break;
                // SELECTION
                case 80 : selection = (max-1 >= selection+1 ? selection+1 : 0 ); break; 
                case 72 : selection = (0 <= selection-1 ? selection-1 : max-1); break;
                // ACTION
                case 77 : action = (3 >= action+1 ? action+1 : 0 ); break; 
                case 75 : action = (0 <= action-1 ? action-1 : 3 ); break;
            }
            if(keypress == 13 || keypress == 32) break; 
            else if (keypress == 27){fclose(mainFile); return 0;}
        }
        switch(action) {
            case 0 : searchPost (mainFile); break;
            case 1 : addPost (mainFile); break;
            case 2 : removePost (mainFile,(page-1)*10 + selection); break;
            case 3 : updatePost (mainFile,(page-1)*10 + selection); break;
        }
    }
    fclose(mainFile);
    return 0;
}

void mainScreen (FILE * f, int sele,int act, int page,int* max,int* maxpage) {
    int n;
    Data buf;
    fseek(f,((page-1)*10) * sizeof(Data),SEEK_SET);
    for(n = 0; fread(&buf, sizeof(Data), 1, f) && n < (page * 10); n++) {
        if(sele == n) printf(">");
        printf("[%02d/%02d/%02d %02d:%02d] : %s : %s \n", buf.date.tm_mday,buf.date.tm_mon+1,buf.date.tm_year+1900, buf.date.tm_hour, buf.date.tm_min,buf.header,buf.content);
    }
    *max = n;
    *maxpage = (ftell(f)/sizeof(Data)/10)+1;
    printf("(%d / %d)\n",page,*maxpage);
    fseek(f,0,SEEK_SET);
    if(act == 0) printf(">"); printf("Rechercher\t");
    if(act == 1) printf(">"); printf("Ajouter\t");
    if(act == 2) printf(">"); printf("Supprimer\t");
    if(act == 3) printf(">"); printf("Modifier\t\n");
    printf("\n\t[INPUTS]\n\t [UP] SELECTION [DOWN]\n\t [LEFT] ACTION [RIGHT]\n\t [Q] PAGE [D]\n\t [ESC] QUIT");
}

void searchPost (FILE* f) {
    clr();
    char search[500];
    StrGet (search,500,"RECHERCHER UN FICHIER :\n  Recherche : \t");

    Data pi;
    printf("RECHERCHE : %s \n##############################\n", search);
    while (fread(&pi, sizeof(Data), 1, f)) {
        if(stristr(pi.header,search) || stristr(pi.content,search))
            printf("[%02d/%02d/%02d %02d:%02d] : %s : %s \n", pi.date.tm_mday,pi.date.tm_mon+1,pi.date.tm_year+1900, pi.date.tm_hour, pi.date.tm_min,pi.header,pi.content);
    } 
    printf("##############################");
    fseek(f,1,SEEK_CUR);
    getch();
}

void addPost (FILE* f) {
    Data postit;
    clr();
    StrGet (postit.header,100,"AJOUTER UN FICHIER :\n  L'en-tete de votre PostIt : \t");
    printf("AJOUTER UN FICHIER :\n  L'en-tete de votre PostIt : \t%s\n",postit.header);
    StrGet (postit.content,500,"  Le contenu de votre PostIt : \t");

    time_t t = time(NULL);
    postit.date = *localtime(&t);
    fseek(f,0,SEEK_END);

    if(fwrite(&postit, sizeof(postit), 1, f)) endFunc("Ajout reussit.",f);
    else endFunc("Echec de l\'ajout.",f);
    getch();
}
void removePost (FILE* f, int select) {
    clr();
    fseek(f,select * sizeof(Data),SEEK_SET);

    Data buf;
    fread(&buf, sizeof(Data), 1, f);
    printf("Voulez vous vraiment supprimer '%s : %s' ? (y/n)",buf.header,buf.content); 
    char keycode;
    do {keycode = getch();} while (keycode != 'n' && keycode != 'y');
    if(keycode == 'n') return;

    fseek(f,-sizeof(Data),SEEK_END);
    fread(&buf, sizeof(Data), 1, f);

    fseek(f,select * sizeof(Data),SEEK_SET);
    fwrite(&buf, sizeof(Data), 1, f);

    fseek(f,-sizeof(Data),SEEK_END);
    ftruncate(fileno(f), ftell(f));

    endFunc ("Suppression reussie.",f);
}
void updatePost (FILE* f, int select) {
    clr();
    fseek(f,select * sizeof(Data),SEEK_SET);
    Data buf;
    fread(&buf, sizeof(Data), 1, f);
    
    int keypress= 0,selection = 0;
    do {
        clr();
        printf("Que voulez vous modifier ?\n");
        if(selection == 0) printf(">"); printf("Titre (%s)\n", buf.header);
        if(selection == 1) printf(">"); printf("Contenu (%s)\n", buf.content);
        if(selection == 2) printf(">"); printf("Titre & Contenu (%s,%s)\n",buf.header,buf.content);

        switch(keypress = getch()) {
            case 80 : selection = (2 >= selection+1 ? selection+1 : 0 ); break; 
            case 72 : selection = (0 <= selection-1 ? selection-1 : 2 ); break;
        }
        if (keypress == 27) return;

    } while (keypress != 13 && keypress != 32);
    
    switch(selection) {
        case 0 : StrGet (buf.header,100,"MODIFIER UN FICHIER :\n  L'en-tete de votre PostIt : \t");break;
        case 1 : { 
            printf("MODIFIER UN FICHIER :\n  L'en-tete de votre PostIt : \t%s\n",buf.header);
            StrGet (buf.content,500,"  Le contenu de votre PostIt : \t");
            break;
        }
        case 2 : {
            StrGet (buf.header,100,"MODIFIER UN FICHIER :\n  L'en-tete de votre PostIt : \t");
            printf("MODIFIER UN FICHIER :\n  L'en-tete de votre PostIt : \t%s\n",buf.header);
            StrGet (buf.content,500,"  Le contenu de votre PostIt : \t");
            break;
        }
    }

    fseek(f,select * sizeof(Data),SEEK_SET);
    fwrite(&buf, sizeof(Data), 1, f);

    endFunc ("Modification reussie.",f);
}