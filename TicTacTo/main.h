#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define clr() system ("CLS");
#define default 0

void tableScreen (int[],int,int);
int rowChangePos (int,int,int[]);
int rowChangeNeg (int,int,int[]);
int whoWin (int[]);