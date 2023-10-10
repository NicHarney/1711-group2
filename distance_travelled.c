#include <stdio.h>

int main(){

    long speed_of_light = 3 * 10^8;
    int days;
    float distance_travelled;


    printf("Enter the number of days the light has been travelling");
    scanf("%d",&days);

    distance_travelled = speed_of_light * days;

    printf("The distance travelled by the light is %g\n km",distance_travelled);
    return 0;
}