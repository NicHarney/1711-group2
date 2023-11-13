
#ifndef FITNESS_DATA_STRUCT_H
#define FITNESS_DATA_STRUCT_H

#include <stdio.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Helper function prototypes
void tokeniseRecord(const char *input, const char *delimiter, char *date, char *time, char *steps);

#endif // FITNESS_DATA_STRUCT_H

FILE open_file(char *fileName, char *mode){
	FILE *file = fopen(fileName,mode);
    if (!file){
        printf("Error opening file\n");
        return 1;
    }

	return file;
}


int display_records(FITNESS_DATA *dataArray,int numLines){
	printf("Number of records in file: %d\n",numLines);
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

                printf("Largest steps: %s %s %d \n",largest_date,largest_time,largest_steps);
}