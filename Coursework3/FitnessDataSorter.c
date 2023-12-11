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
void tokeniseRecord(char *record, char delimiter, char *date, char *time, char *steps) {
    char *ptr = strtok(record, &delimiter);
    if (ptr != NULL) {
        strcpy(date, ptr);
        ptr = strtok(NULL, &delimiter);
        if (ptr != NULL) {
            strcpy(time, ptr);
            ptr = strtok(NULL, &delimiter);
            if (ptr != NULL) {
                //*steps = atoi(ptr);
                strcpy(steps,ptr);
            }
        }
    }
}

//function to tell the qsort function how to order the fitness array
int compare(const void* num1, const void* num2){

    const FitnessData *a = (const FitnessData *) num1;
    const FitnessData *b = (const FitnessData *) num2;
    
    //as steps needs to be in descending order, if a > b then don't swap
    if (a->steps > b->steps){
        return -1;
    
    }
    
    //if a < b then swap
    else if (a->steps < b->steps){
        return 1;
    }

    //don't swap if they are the same
    return 0;
}


int main() {
    
    //intialise variables
    FitnessData fitness[1000];
    int buffer_size = 1000;
    char line_buffer[buffer_size];
    char filename[buffer_size];
    char date[11];
    char time[6];
    char steps[100];
    int line_number = 0;
    int i = 0;
    char new_file[] = ".tsv";

    //gets users file input
    printf("Enter Filename: ");

    fgets(line_buffer, buffer_size, stdin);
    sscanf(line_buffer, " %s ", filename);
    
   


    //opens the file
	FILE *file = fopen(filename,"r");
    if (file == NULL){
        
        return 1;
        
    }
    

    //writes file information to fitness struct
	while (fgets(line_buffer,buffer_size,file)){

        tokeniseRecord(line_buffer,',',date,time,steps);

        //copy contents stored in the temporary variables to the array struct
        strcpy(fitness[i].date,date);
        strcpy(fitness[i].time,time);
        fitness[i].steps = atoi(steps);
        
        i++;
        line_number++;
    }
    
    //built in function used to sort arrays
    qsort(fitness,line_number,sizeof(FitnessData),compare);

    
    
    fclose(file);

    //concatenate strings to createa new file
    strcat(filename,new_file);

    //create a new write file 
    FILE *file2 = fopen(filename,"w");

    //write each element of fitness to the new file
    for(int i = 0; i < line_number;i++){
        fprintf(file2, "%s %s %d\n", fitness[i].date,fitness[i].time,fitness[i].steps);
    }
    fclose(file2);

    printf("Data sorted and written to %s\n",filename);
}
