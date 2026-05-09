#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Student File System in C

- Stores student data using structs
- Dynamically allocates memory for students
- Reads student information from user input
- Saves data to a text file using file handling
- Demonstrates structs, pointers, dynamic memory allocation, loops, and file I/O
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

    FILE* fl;
    
    fl=fopen("file.txt","w");
    if(fl==NULL){
        printf("Error! opening file");
        exit(1);
    }

    for(int i = 0; i<studentNmbr; i++){
        fprintf(fl,"%s %s %d\n",stdntArray[i].Name,stdntArray[i].Grade,stdntArray[i].Age);
    }

    free(stdntArray);
    fclose(fl);
    return 0;
}