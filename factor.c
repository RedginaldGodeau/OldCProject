#include <stdio.h>
#include <stdlib.h>

int fact (int result,int i,int max) {
    result *= i;
    i++;

    if(i > max) {
        return result;
    } else {
        return fact(result,i,max);
    }
}



int main(int argc, char const *argv[]) {
    
    int factor = 0;

    scanf("%d",&factor);
    printf("%d", fact(1,1,factor) );


    return 0;
}
