#include <stdio.h>

int main(){

    int number,mean=0,i=0;

    for (i = 0; i < 10; i++){
        number = 0;
        printf("Enter a number: ");
        scanf("%d",&number);

        mean += number;
    }

    mean = mean/10;

    printf("The mean is: %d\n",mean);

    return 0;
}