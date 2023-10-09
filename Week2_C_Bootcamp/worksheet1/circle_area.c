#include <stdio.h>
#include <math.h>
int main(){

    float radius,area; 
    

    printf("Enter the radius of the circle: ");
    scanf("%f",&radius);

    area = radius * radius * M_PI;
    printf("The area of the circle is: %g\n",area);
    return 0;
}