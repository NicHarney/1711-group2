#include <stdio.h>

int main() {

    int i,a;

    for(i = 1; i < 13; i++){

        for (a =1; a < 13; a++){

            printf("%d times %d is %d\n ",i,a, i*a);
        }
    }

    printf("Times table finished");

    return 0;
}