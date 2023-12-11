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
    char menu_choice;
   
    char line_buffer[buffer_size];
    char filename[buffer_size];
    int i = 0;
    char date[11];
    char time[6];
    char steps[100];
    int line_number = 0;
    
    bool exit = false;
    bool file_inputted = false;
   
    
    while(true){


        //display mennu options
        printf("Menu Options:\n");
        printf("A: Specify the File name to be imported\n");
        printf("B: Display the total number of records in the file \n");
        printf("C: Find the date and time of the timeslot with the fewest steps\n");
        printf("D: Find the date and time of the timeslot with the largest number of steps\n");
        printf("E: Find the mean step count of all the records in the file\n");
        printf("F: Find the longest continuous period where the step count is above 500 steps\n");
        printf("Q: Exit\n");
        scanf(" %c",&menu_choice);

        while (getchar() != '\n');

        //check the user has not already inputted a file
        if (file_inputted == false){

            //check if the user has decided to input a file at all
            if (menu_choice == 'A' || menu_choice == 'a'){
                
                FILE *file = open_file(filename,"r");
                if (file == NULL)
                    return 1;
                while (fgets(line_buffer,buffer_size,file)){

                        tokeniseRecord(line_buffer,",",date,time,steps);

                        //copy contents stored in the temporary variables to the array struct
                        strcpy(fitness[i].date,date);
                        strcpy(fitness[i].time,time);
                        fitness[i].steps = atoi(steps);

                        i++;
                        line_number++;
                }
            }
        
        }

       if (menu_choice == 'q' || menu_choice == 'Q'){
        break;
       }

    

        
        //case statement deciding which function to go to
        if (file_inputted == true){
            switch(menu_choice){
                case 'A': 
                case 'a':
                    printf("Filename already specified\n");
                    break;
                    
                case 'B': 
                case 'b':
                    display_records(fitness,line_number);
                    break;

                case 'C':
                case 'c':
                    steps_lowest(fitness, line_number);
                    break;
                    
                case 'D':
                case 'd':
                    steps_highest(fitness, line_number);
                    break;
                case 'E':
                case 'e':
                    mean_steps(fitness,line_number);
                    break;
                case 'F':
                case 'f':
                    steps_continued(fitness,line_number);
                    break;
                default:
                    printf("Invalid input\n");
                    break;
                
            }
        } 
        else{
            if (menu_choice != 'A' && menu_choice != 'a'){
                printf("Filename needs to be specified\n");
            }
            else{
                file_inputted = true;
            }
        }  
        
    }

    
    

    return 0;
}













