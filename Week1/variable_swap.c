#include <stdio.h>

int main(){

    int num1,num2,temp;
    printf("Enter your first number");
    scanf("%d",&num1);
    printf("Enter your second number");
    scanf("%d",&num2);
    temp = num1;
    num1 = num2;
    num2 = temp;
    printf("The first number is now: %d\n",num1);
    printf("The second number is now: %d\n",num2);
    return 0;

}