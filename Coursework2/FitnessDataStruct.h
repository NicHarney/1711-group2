
#ifndef FITNESS_DATA_STRUCT_H
#define FITNESS_DATA_STRUCT_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define buffer_size 1000

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Helper function prototypes
void tokeniseRecord(const char *input, const char *delimiter, char *date, char *time, char *steps);

#endif // FITNESS_DATA_STRUCT_H

FILE *open_file(char *filename, char *mode){
    char line_buffer[buffer_size];
    //char filename2[100];
     printf("Enter the file name: ");

    fgets(line_buffer, buffer_size, stdin);
    sscanf(line_buffer, " %s ", filename);
    //getchar();
	FILE *file = fopen(filename,mode);
    if (file == NULL){
        printf("Error opening file\n");
        return NULL;
        
    }
    else{
        printf("File successfully loaded.\n");
    }

	return file;
}


int display_records(FITNESS_DATA *dataArray,int numLines){
	printf("Total records: %d\n",numLines);
}

int steps_lowest(FITNESS_DATA *dataArray, int numLines){

	int fewest_steps = dataArray[0].steps;
    char fewest_date[11]; strcpy(fewest_date, dataArray[0].date);
    char fewest_time[6]; strcpy(fewest_time, dataArray[0].time);
	int i = 0;


	for (i = 0; i < numLines; i++){

                    if (dataArray[i].steps < fewest_steps){
                        fewest_steps = dataArray[i].steps;
                        strcpy(fewest_date, dataArray[i].date);
                        strcpy(fewest_time, dataArray[i].time);

                    }
                }
                
                printf("Fewest steps: %s %s \n",fewest_date,fewest_time);
                
}

int steps_highest(FITNESS_DATA *dataArray, int numLines){

	int largest_steps = dataArray[0].steps;
    char largest_date[11]; strcpy(largest_date,dataArray[0].date);
    char largest_time[6]; strcpy(largest_time,dataArray[0].time);
	int i = 0;


	for (i = 0; i < numLines; i ++){

                    if (dataArray[i].steps > largest_steps){
                        largest_steps = dataArray[i].steps;
                        strcpy(largest_date,dataArray[i].date);
                        strcpy(largest_time,dataArray[i].time);
                    }
                }

                printf("Largest steps: %s %s  \n",largest_date,largest_time);
}

int mean_steps(FITNESS_DATA *dataArray,int numLines){
    float mean_steps = 0;
    for (int i = 0; i < numLines; i++){
        mean_steps += dataArray[i].steps;
    }

    mean_steps = mean_steps/numLines;

    printf("Mean step count: %.0f\n",mean_steps);
}

int steps_continued(FITNESS_DATA *dataArray, int numLines){
    int count = 0;
    int highest_count = 0;
    char longest_start_date[200];
    char longest_start_time[200];
    char longest_end_date[200];
    char longest_end_time[200];
    int temp = 0;
   
    for (int i = 0; i < numLines; i++){

        if (dataArray[i].steps > 500){
            count+= 1;
        }
        else{
            if (count > highest_count){
                highest_count = count;
                
                strcpy(longest_start_date,dataArray[temp].date);
                strcpy(longest_start_time, dataArray[temp].time);
                strcpy(longest_end_date, dataArray[i-1].date);
                strcpy(longest_end_time, dataArray[i-1].time);
                
            }
            count = 0;
            temp = i + 1;
        }
        
    }

    printf("Longest period start: %s %s \nLongest period end: %s %s \n",longest_start_date, longest_start_time, longest_end_date, longest_end_time);
}