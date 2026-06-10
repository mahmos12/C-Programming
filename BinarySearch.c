#include <stdio.h>

/*
SORTING:
- Iterates through the array and compares each element with the following ones
- Swaps elements if they are in the wrong order
- Result is an ascending sorted array

BINARY SEARCH:
- Requires a sorted array
- Uses two boundaries: left and right
- Computes middle index (mid) each iteration
- Compares target with array[mid]
    - equal -> found
    - greater -> move left to mid + 1 (discard left half)
    - smaller -> move right to mid - 1 (discard right half)
- Repeats until left > right or value is found
*/


int main(){
    int array[] = {1,2,3,5,7,9,10,15,4,30};
    int len = sizeof(array)/sizeof(array[0]);

    // sort array
    for(int i= 0; i<len; i++){
        for(int j=i+1;j<len;j++){
            if(array[i]>array[j]){
                int temp = array[i];
                array[i] = array[j];
                array[j]= temp;
            }
        }
    }

    for(int i= 0; i<len; i++){
        printf("%d\t",array[i]);
    }
    printf("\n");

    int target = 10;
    int left = 0;
    int right = len - 1;
    int found = 0;

    while(left <= right){
        int mid = (left + right) / 2;

        if(target == array[mid]){
            printf("target {%d} found at index {%d}\n", array[mid], mid);
            found = 1;
            break;
        }

        if(target > array[mid]){
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if(!found){
        printf("target not found\n");
    }

    return 0;
}