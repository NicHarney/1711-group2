#include <stdio.h>


//declaring how to convert from f to c
float fahr_to_celsius (float f_temp)
{
    float c_temp;
    c_temp = (f_temp - 32)/1.8;
    return c_temp;
}


//declaring how to convert from f to k
float fahr_to_kelvin (float f_temp)
{
    float k_temp;
    k_temp = fahr_to_celsius(f_temp) + 273.15;
    return k_temp;
}

float fahr_to_newt(float f_temp){

    float newt_temp;
    newt_temp = (f_temp - 32) * 11/60;
    return newt_temp;
}

int main () 
{
    float fahrenheit;
    char option;

    printf ("Enter a temperature to convert in Fahrenheit:\n");
    scanf ("%f", &fahrenheit);

    printf ("\n");
    printf ("Select A to convert to Celsius\n");
    printf ("Select B to convert to Kelvin\n");
    printf("Select C to convert to newtons\n");
    printf ("Select Q to quit\n");

    scanf(" %c", &option);
    

    //send code to different function depending on user input
    switch (option)
    {
        case 'A': printf ("Converted to degrees Celsius: %f\n", fahr_to_celsius(fahrenheit));
                  break;

        case 'B': printf ("Converted to Kelvin: %f\n", fahr_to_kelvin(fahrenheit));
                  break;
        case 'C': printf("Convert to newtons: %f\n",fahr_to_newt(fahrenheit));

        case 'Q': break;

        default:  break;
    }

    return 0;
}