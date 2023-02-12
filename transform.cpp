#include <stdio.h>
#include <stdlib.h> 
#include <conio.h>
#include <string.h>

#define maxchar 40

int i = 0;

int transformlet (char ph[]) {
	char ret[maxchar];
	int c = 0;
	
	for(i = 0; i != '\0'; i++) {
		if(ph[i] > 'a' && ph[i] < 'z' || ph[i] > 'A' && ph[i] < 'Z') {
			ph[i] = tolower(ph[c++]);
		}
	}
	
	
	c = 0;
	for(i = strlen(ph)-1; i!=-1; i--) {
			ret[c++] = ph[i];	
	}

	printf("|%s|%s|",ret,ph);

	return strcmp(ret,ph);
}



int main() {

	char op[maxchar];
	fgets(op,maxchar,stdin);
	
	printf("%d", transformlet(op));

	return 0;
}
