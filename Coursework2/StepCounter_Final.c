#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"
#include <stdbool.h>

// Struct moved to header file

// Define any additional variables here
// Global variables for filename and FITNESS_DATA array


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
    bool exit = false;
    bool file_inputted = false;

    //opening file
    FILE *file = fopen("FitnessData_2023.csv","r");
    if (file == NULL){
        printf("Error opening file\n");
        return 1;
    }

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
    while(exit == false){

    
        char menu_choice;

        printf("Menu Options:\n");
        printf("A: Specify the File name to be imported\n");
        printf("B: Display the total number of records in the file \n");
        printf("C: Find the date and time of the timeslot with the fewest steps\n");
        printf("D: Find the date and time of the timeslot with the largest number of steps\n");
        printf("E: Find the mean step count of all the records in the file\n");
        printf("F: Find the longest continuous period where the step count is above 500 steps\n");
        printf("Q: Exit\n");
        scanf(" %c",&menu_choice);


        int fewest_steps = fitness[0].steps;
        char fewest_date[11]; strcpy(fewest_date, fitness[0].date);
        char fewest_time[6]; strcpy(fewest_time, fitness[0].time);

        int largest_steps = fewest_steps;
        char largest_date[11]; strcpy(largest_date,fitness[0].date);
        char largest_time[6]; strcpy(largest_time,fitness[0].time);

        switch(menu_choice){
            case 'A': file_inputted = true;
                break;
            if file_inputted == true;
                case 'B':printf("Number of records in file: %d\n",line_number);
                    break;

                case 'C':
                

                    for (i = 0; i < line_number; i++){

                        if (fitness[i].steps < fewest_steps){
                            fewest_steps = fitness[i].steps;
                            strcpy(fewest_date, fitness[i].date);
                            strcpy(fewest_time, fitness[i].time);

                        }
                    }
                    
                    printf("Fewest steps: %s %s \n",fewest_date,fewest_time);
                    break;
                case 'D':
                    for (i = 0; i < line_number; i ++){

                        if (fitness[i].steps > largest_steps){
                            largest_steps = fitness[i].steps;
                            strcpy(largest_date,fitness[i].date);
                            strcpy(largest_time,fitness[i].time);
                        }
                    }

                    printf("Largest steps: %s %s %d \n",largest_date,largest_time,largest_steps);
                    break;
                case 'Q':
                    exit = true;
            else{
                printf("Specify a valid file to be imported\n")
            }
        }   
    }
    //display number of records stored
    
    
    //print the record stored if its in the first 3 file lines
   // for(i = 0; i<3;i++){

       // printf("%s/%s/%d\n",fitness[i].date,fitness[i].time,fitness[i].steps);
   // }
    
    fclose(file);

    return 0;
}













