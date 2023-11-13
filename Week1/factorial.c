#include <stdio.h>
#include <math.h>
int main(){

    int number;
    int temp_number;
    printf("Enter a number: ");
    scanf("%d",&number);
    temp_number = number - 1;
    for (temp_number; temp_number>0; temp_number--){
        number = number*temp_number;
        
    }

    printf("The factorial of the number is %d\n",number);
    return 0;
}