#include <stdio.h>
#include <stdlib.h>
int main() {
    char* filename = "data.txt";
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }


    //number of characters whih will be read per line
    int buffer_size = 100;
    //a string which will hold each line as it's read in
    char line_buffer[buffer_size];
    int numbers[1000];
    int line_number = 0;
    //while there is still stuff in the file
    while (fgets(line_buffer, buffer_size, file) != NULL) {
        printf("%d\n", atoi(line_buffer));

        numbers[line_number] = atoi(line_buffer);

        printf("%d\n",numbers[line_number]);
        line_number++;
        
    }

    fclose(file);
    return 0;
}