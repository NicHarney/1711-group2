#include <stdio.h>
#include <stdlib.h>


int main(){

    char* filename = "numbers.dat";

    FILE *file = fopen(filename,"a+");

    if (file == NULL){
        printf("Error opening file\n");
        return 1;
    }

    int buffer_size = 100;
    char line_buffer[buffer_size];
    float mean = 0;
    int line_number = 0;

    while (fgets(line_buffer,buffer_size,file)!= NULL){
        mean += atoi(line_buffer);
       
        line_number++;

    }
    mean = mean/line_number;

    printf("The mean is: %g\n",mean);

    fprintf(file,"%g\n",mean);
    fclose(file);
}