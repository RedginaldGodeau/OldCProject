#include <stdio.h>
#include <stdlib.h> 
#include <conio.h>
#include <string.h>

#define maxchar 40
 
void getunit (int p) { // 16
    switch(p) {
        case 1 : printf("Un"); break;
        case 2 : printf("Deux"); break;
        case 3 : printf("Trois"); break;
        case 4 : printf("Quatre"); break;
        case 5 : printf("Cinq"); break;
        case 6 : printf("Six"); break;
        case 7 : printf("Sept"); break;
        case 8 : printf("Huit"); break;
        case 9 : printf("Neuf"); break;
    }  
}

void getonzaine (int p) {
    switch(p) {
        case 10 : printf("Dix"); break;
        case 11 : printf("Onze"); break;
        case 12 : printf("Douze"); break;
        case 13 : printf("Tréze"); break;
        case 14 : printf("Quatorze"); break;
        case 15 : printf("Quinze"); break;
        case 16 : printf("Sexe"); break;
        case 17 : printf("Dix-sept"); break;
        case 18 : printf("Dix-huit"); break;
        case 19 : printf("Dix-neuf"); break;
    }  
}

void prefix (int p) {
        if(p == 1) printf("Et "); else if(p != 0) printf("-");
}

void getdiziane (int p){
	switch(p) {
		case 2: printf("Vingt "); break;
		case 3: printf("Trente "); break;
		case 4: printf("Quarante "); break;
		case 5: printf("Cinquante "); break;
		case 6: printf("Soixante "); break;
		case 7: printf("Septante "); break;
		case 8: printf("Huitante "); break;
		case 9: printf("Nonante "); break;		 
	}
}



int main() {
    int number, getzero;
    scanf("%d",&number);
    getzero = 0;


	if(number >= 1000 && number <= 9999) {
		if(number/1000 != 1 ) getunit(number / 1000);
		
		getzero = 1;
		
		printf(" Mille ");
		number-= (number/1000)*1000;
	}
	
	if(number >= 100 && number <= 999) {
		
		if(number/100 != 1) {
			getunit(number / 100);
			
			if(number % 100 > 0) printf(" Cent "); else printf(" Cents");
			
		} else printf(" Cent ");
		
		getzero = 1;
		
		number-= (number/100)*100;
	}
	
	if(number >= 20 && number <= 99) {
		getdiziane(number/10);
		number -= (number/10) * 10;
		getzero = 1;
		
		prefix(number);
	}
	
	if(number >= 10 && number <= 19) {
		getonzaine(number);
	}  else if(number < 10) {
		
		if(!getzero && number == 0) {
			printf("Zero");
		} else getunit(number);
	}
	 

    return 0;
}
