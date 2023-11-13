#include <stdio.h>
#include <math.h>
int main(){

    float principal, rate,time;
    

    printf("Enter the original amount of money: ");
    scanf("%f",&principal);
    
    printf("Enter the rate of increase: ");
    scanf("%f",&rate);

    printf("Enter the number of years the interest is across: ");
    scanf("%f",&time);
    
    for(time; time>0; time--){
        principal = principal*rate;
    }

    

    printf("The new amount of money is %.2f\n",principal);

    return 0;
}