#include <stdio.h>

float calc(float a, float b, char c){

    
    
    switch(c)
    {
        case '+': printf("The answer is: %f\n",a + b);
            break;
        
        case '-': printf("The answer is: %f\n",a - b);
            break;

        case '*':printf("The answer is: %f\n",a * b);
            break;

        case '/':printf("The asnwer is %f\n",a/b);
            break;
        default: break;


    }
}


int main(){

    float num1,num2;
    char option;

    printf("Enter the first number: ");
    scanf("%f",&num1);

    printf("Enter the second number: ");
    scanf("%f",&num2);

    printf("Enter the operation required: ");
    scanf(" %c",&option);

    
    calc(num1,num2,option);

    return 0;
}