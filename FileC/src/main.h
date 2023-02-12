#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <time.h> 
#include <unistd.h>

#define clr() system ("CLS");
#define bool signed short int
#define true 1;
#define false 0;

typedef struct Data {
    char header[100];
    char content[500];
    struct tm date;
} Data;

void mainScreen (FILE*, int,int,int,int*,int*);
void searchPost (FILE*);
void addPost (FILE*);
void removePost (FILE*, int);
void updatePost (FILE*, int);