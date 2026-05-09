#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/*
Dynamic array sum program in C.

- Reads how many numbers the user wants to enter
- Allocates memory dynamically using malloc
- Stores numbers in an array
- Uses a function to calculate the sum
- Prints the result
- Demonstrates pointers, arrays, functions, and dynamic memory allocation
*/


int Sum(int *array, int size){
    int sum=0;
    for(int i= 0; i<size; i++){
        sum+=array[i];
    }
    return sum;
}

int main(){

    printf("How many number you will enter? ");
    int size;
    scanf("%d",&size);
    int *array;
    array = malloc(size *sizeof(int));

    for(int i = 0; i<size; i++){
        printf("Enter yot number: ");
        scanf("%d",&array[i]);
    }
    int sum = Sum(array,size);
    printf("Sum is: %d", sum);
    return 0;
}
