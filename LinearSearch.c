#include <stdio.h>

/*
    Linear Search Algorithm

    - Traverses the array one element at a time
    - Compares each element with the target value
    - If target is found:
        * prints the value and index
        * sets found flag to 1
        * stops loop using break
    - If target is not found after traversal:
        * prints "Not found"
*/

int main(){
    int array[8] = {5,2,9,1,7,10,3,15};
    int target =7;
    int len = sizeof(array)/sizeof(array[0]);
    int found = 0;
    for(int i=0; i<len; i++){
        if(target==array[i]){
            printf("Found %d at index: %d",array[i],i);
            found=1;
            break;
        }
    }
    if(found==0){
        printf("Not found");
    }
    return 0;
}