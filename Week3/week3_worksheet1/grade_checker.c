#include <stdio.h>

int main(){

    int grade;

    printf("Please enter your grade: ");
    scanf("%d",&grade);

    if (grade >= 70 && grade <= 100){
        printf("You achieved a distinction!\n");

    }
    else if(50 <= grade && grade < 70){
        printf("You passed!\n");

    }
    else if(0 <= grade && grade < 50){
        printf("You failed!\n");

    }
    else{
        printf("Please enter a valid grade between 0 and 100");
    }

    return 0;
}