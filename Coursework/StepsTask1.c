#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Define any additional variables here



// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

}

// Complete the main function
int main() {
    
    //declaring array structure and file variables
    FITNESS_DATA fitness[1000];
    int buffer_size = 250;
    char line_buffer[buffer_size];
    int i = 0;

    //opening file
    FILE *file = fopen("FitnessData_2023.csv","r");
    if (file == NULL){
        printf("Error opening file\n");
        return 1;
    }

    //declaring temporary variables read from the file
    char date[11];
    char time[6];
    char steps[100];
    int line_number = 0;

    //filter through the file line by line and storing each variable
    while (fgets(line_buffer,buffer_size,file)){

        tokeniseRecord(line_buffer,",",date,time,steps);

        //copy contents stored in the temporary variables to the array struct
        strcpy(fitness[i].date,date);
        strcpy(fitness[i].time,time);
        fitness[i].steps = atoi(steps);

        i++;
        line_number++;
    }

    //display number of records stored
    printf("Number of records in file: %d\n",line_number);
    
    //print the record stored if its in the first 3 file lines
    for(i = 0; i<3;i++){

        printf("%s/%s/%d\n",fitness[i].date,fitness[i].time,fitness[i].steps);
    }
    
    fclose(file);

    return 0;
}
