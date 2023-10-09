#include <stdio.h>

int main(){

    float length;
    float width;
    float area;
    printf("Enter the length: ");
    scanf("%f", &length);
    printf("Enter the width: ");
    scanf("%f",&width);
    area = length * width;
    printf("The area of the rectangle is %.3f\n",area);
}