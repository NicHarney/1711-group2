#include <stdio.h>

int main(){

    float fahrenheit;
    float celsius;

    printf("Enter the temperature in fahrenheit: ");
    scanf("%f",&fahrenheit);

    celsius = (fahrenheit -32)*5/9;

    printf("The temperature in celsius is: %g\n",celsius);
}