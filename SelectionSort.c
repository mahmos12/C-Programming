#include <stdio.h>

/*
Implemented Selection Sort in C using
 nested loops and value swapping 
 with a temporary variable.
  Added array printing before
   and after sorting to visualize 
   the algorithm step by step.
*/

int main(){
    int array[5] = {5, 2, 9, 1, 7};

    int len = sizeof(array)/sizeof(array[0]);
   
    printf("befor sort:\n ");
    for(int i = 0; i<len; i++){
        printf("%d\t",array[i]);
    }

    for(int i=0; i<len;i++){
        int minIndex=i;
        for(int j=i+1; j<len; j++){
            if(array[j]<array[minIndex]){
                minIndex=j;
            }
        }
        int temp = array[i];
        array[i] = array[minIndex];
        array[minIndex] = temp;
    }
     printf("\nAfter sort:\n ");
    for(int i = 0; i<len; i++){
        printf("%d\t",array[i]);
    }


    return 0;
}