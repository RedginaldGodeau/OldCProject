#include "main.h"

int main(int argc, char const *argv[]) {

    int table[9] = {default,default,default,default,default,default,default,default};
    int round = 1;
    for (int i = 0; i < 9; i++) {
        int row = rowChangePos(-1,1,table);
        while (1) {
            clr();
            tableScreen (table,row,round);
            int keypress = 0;
            switch(keypress = getch()) {
                // LEFT & RIGHT
                case 77 : row = rowChangePos(row,1,table); break; 
                case 75 : row = rowChangeNeg(row,1,table); break;
                // UP & DOWN
                case 80 : row = rowChangePos(row,3,table); break; 
                case 72 : row = rowChangeNeg(row,3,table); break;
            }
            if(keypress == 13 || keypress == 32) break; 
            else if (keypress == 27) return 0;
        }
        table[row] = round;
        round = (round == 1 ? 2 : 1);

        switch(whoWin (table)) {
            case 1 : clr(); printf("Joueur O gagne !");  return 0;
            case 2 : clr(); printf("Joueur X gagne !");  return 0; 
        } 
    }

    clr();
    printf("Egalite");
    return 0;
}

int rowChangePos (int r,int add,int t[]) {
    int v = (r+add > 8 ? 0 : r+add);
    while (t[v] != default) v = (v+add) % 9;
    return v;
}
int rowChangeNeg (int r,int neg,int t[]) {
    int v = (r-neg < 0 ? 8 : r-neg);
    while (t[v] != default) v = (v-neg < 0 ? 8 : v-neg);
    return v;
}

void tableScreen (int t[],int row,int round) {
    int i = 0,c = 0 ,l = 0;
    for (i = 0; i < 9; i++) {
        char p = '_';
        if(i % 3 == 0) printf("\n");
        if(t[i] == 1) p = 'O'; else if(t[i] == 2) p = 'X';
        if(row == i) p = (round == 1 ? 'O' : 'X');
        printf("%c", p);
    }
}

int whoWin (int t[]) {

    for (int i = 0; i < 3; i++) {
        if(t[i] != default && t[i+1] != default && t[i+2] != default)
            switch(t[i]+t[i+1]+t[i+2]) {
                case 3 : return 1;
                case 6 : return 2;
            }
        else if(t[i] != default && t[i+3] != default && t[i+6] != default)
            switch(t[i]+t[i+3]+t[i+6]) {
                case 3 : return 1;
                case 6 : return 2;
            }
    }
    if(t[0] != default && t[4] != default && t[8] != default)
        switch(t[0]+t[4]+t[8]) {
            case 3 : return 1;
            case 6 : return 2;
        }
    else if(t[2] != default && t[4] != default && t[6] != default)
        switch(t[2]+t[4]+t[6]) {
            case 3 : return 1;
            case 6 : return 2;
        }
    return 0;

}