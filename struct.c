#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Student Management System in C

- Uses structs to store student information
- Dynamically allocates memory for multiple students
- Reads student name, grade, and age from user input
- Displays all stored student data
- Demonstrates structs, dynamic memory allocation, arrays, loops, and user input handling
*/

typedef struct{
    char Name [20];
    char Grade[10];
    int Age;
}Student;


int main(){
    printf("How many students? ");
    int studentNmbr;
    scanf("%d", &studentNmbr);

    Student * stdntArray;
    stdntArray= malloc(studentNmbr *sizeof(Student));

    for(int i = 0; i<studentNmbr; i++){
        printf("Enter your name : ");
        scanf("%s",stdntArray[i].Name);
        printf("Enter your Grade : ");
        scanf("%s",stdntArray[i].Grade);
        printf("Enter your Age : ");
        scanf("%d",&stdntArray[i].Age);
    }

    printf("");

    for(int i =0; i<studentNmbr; i++){
        printf("student: %d\n",i+1);
        printf("Name: %s \n",stdntArray[i].Name);
        printf("Grade: %s \n",stdntArray[i].Grade);
        printf("Age: %d \n",stdntArray[i].Age);
    }
    free(stdntArray);
    return 0;
}