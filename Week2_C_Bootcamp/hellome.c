#include <stdio.h>

int main(){
    // setting up 15 slots of memory for a string
    char name[15];

    // asking user to enter their name
    printf("Hello, please enter you name: ");
    // take the user input and stores it in name
    scanf("%s", name);
    //print users name
    printf("Your name is %s\n", name);

}