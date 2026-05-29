#include <stdio.h>

/*
Implemented Bubble Sort in C
using nested loops and adjacent
element swapping.
Practiced comparison logic,
in-place sorting, 
and array traversal without 
using built-in sorting functions.
*/

int main(){
    int array[8] = {5,2,9,1,7,10,3,50};
    int len = sizeof(array)/sizeof(array[0]);

    for(int i = 0; i<len; i++){
        printf("%d\t",array[i]);
    }
    
    for(int i=0; i<len; i++){
        for(int j=0; j<len-i-1; j++){
            if(array[j]>array[j+1]){

                int temp =array[j];
                array[j]= array[j+1];
                array[j+1]=temp;
            }
        }
    }

    printf("\nAfter sort!\n");
    for(int i = 0; i<len; i++){
        printf("%d\t",array[i]);
    }



    return 0;
}
