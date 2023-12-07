#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for the fitness data
typedef struct {
    char date[11];
    char time[6];
    int steps;
} FitnessData;

// Function to tokenize a record
void tokeniseRecord(char *record, char delimiter, char *date, char *time, int *steps) {
    char *ptr = strtok(record, &delimiter);
    if (ptr != NULL) {
        strcpy(date, ptr);
        ptr = strtok(NULL, &delimiter);
        if (ptr != NULL) {
            strcpy(time, ptr);
            ptr = strtok(NULL, &delimiter);
            if (ptr != NULL) {
                *steps = atoi(ptr);
            }
        }
    }
}


int compare(const void* num1, const void* num2){

    int a = *(int*) num1;
    int b = *(int*) num2;

    if (a > b){
        return -1;
    
    }

    else if (a < b){
        return 1;
    }
    return 0;
}


int main() {
    
    FitnessData fitness[1000];
    int buffer_size = 1000;
    char line_buffer[buffer_size];
    char filename[buffer_size];
    char date[11];
    char time[6];
    char steps[100];
    int line_number = 0;
    int i = 0;
    
    printf("Enter the file name: ");

    fgets(line_buffer, buffer_size, stdin);
    sscanf(line_buffer, " %s ", filename);
    
	FILE *file = fopen(filename,"r");
    if (file == NULL){
        printf("Error opening file\n");
        return 1;
        
    }
    else{
        printf("File successfully loaded.\n");
    }

	while (fgets(line_buffer,buffer_size,file)){

        tokeniseRecord(line_buffer,',',date,time,steps);

        //copy contents stored in the temporary variables to the array struct
        strcpy(fitness[i].date,date);
        strcpy(fitness[i].time,time);
        fitness[i].steps = atoi(steps);
        
        i++;
        line_number++;
    }
    char temp_steps[1000] = fitness.steps;
    qsort(temp_steps,line_number,sizeof(int),compare);

    for(int i = 0; i<3;i++){

        printf("%s/%s/%d\n",fitness[i].date,fitness[i].time,fitness[i].steps);
    }
    
    fclose(file);

}
