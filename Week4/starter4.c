#include <stdio.h>
#include <stdlib.h>
int main(){

    char* filename = "input.txt";
    FILE *file = fopen(filename,"r");

    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }


    int buffer_size = 100;
    char line_buffer[buffer_size];

    int numbers[1000];
    int i = 0;
    while (fgets(line_buffer,buffer_size,file)!= NULL){


        numbers[i] = atoi(line_buffer);

        
        printf("%d\n",numbers[i]);
        i++;
    }

    fclose(file);
}