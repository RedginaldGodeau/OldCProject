#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <time.h> 
#include <ctype.h>

#define clr() system ("CLS");

void OpenFile (FILE** ,const char*);
void purger(void);
void scan_int(int*);
void StrGet (char*, int, const char*);
char* stristr(const char*, const char*);
void endFunc (const char*,FILE*);