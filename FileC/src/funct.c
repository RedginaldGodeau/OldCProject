#include "funct.h"

void OpenFile (FILE** p ,const char* path) {
    *p = fopen(path,"rb+");
    if(!p) *p = fopen(path,"wb+");
}

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

char* stristr(const char* String, const char* Pattern) {
      char *pptr, *sptr, *start;

      for (start = (char *)String; *start; start++) {
            for ( ; (*start && (toupper(*start) != toupper(*Pattern))); start++);
            if (!*start) return 0;

            pptr = (char*)Pattern;
            sptr = (char*)start;

            while (toupper(*sptr) == toupper(*pptr)) {
                  sptr++;
                  pptr++;
                  if (!*pptr) return (start);
            }
      }
      return 0;
}

void endFunc (const char* sentence,FILE * f) {
    printf("%s", sentence);
    fseek(f,0,SEEK_SET);
    getch();
}