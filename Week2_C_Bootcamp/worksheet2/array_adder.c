#include <stdio.h>

int main() {

    int numbers[4],answer,i;

    printf("Enter 5 numbers: ");
    scanf("%d\n %d\n %d\n %d\n %d\n",numbers[0],numbers[1],numbers[2],numbers[3],numbers[4]);

    


    for(i = *numbers; i < *(numbers+4);i++){

        printf("%d\n",i);
        answer = answer + numbers[i];

    }

    printf("The total sum is %d",answer);

    return 0;
}