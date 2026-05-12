#include <stdio.h>
#include <stdlib.h>

/*
Queue implementation using Linked List in C

- Uses dynamic memory allocation with malloc
- Implements queue operations: enqueue, dequeue, and print
- Demonstrates FIFO (First In First Out) behavior
- Uses structs, pointers, double pointers, and linked list traversal
- Properly frees memory to avoid memory leaks
*/

typedef struct Node{
    int data;
    struct Node *next;

}Node;


void enqueue(Node **front, Node **rear, int value){
    Node *newNode;
    newNode=malloc(sizeof(Node));
    newNode->data=value;
    newNode->next=NULL;
    if(*front==NULL){
        *front=newNode;
        *rear= newNode;
        
    }else{
    (*rear)->next=newNode;
    *rear=newNode;

    }

}



void dequeue(Node **front, Node **rear){
    if(*front==NULL){
        printf("Queue is empty! \n");
        return;
    }
    Node *temp = *front;
    *front = (*front)->next;
    if(*front==NULL){
        *rear=NULL;
    }
    free(temp);
}


void printQueue(Node *front){
    Node *temp;
    temp=front;

    while (temp!=NULL)
    {
        printf("%d\t ",temp->data);
        temp=temp->next;
    }
    
}


int main(){
    Node *front = NULL;
    Node *rear = NULL;
    int size;
    int value;
    printf("Queue size? ");
    scanf("%d",&size);

    for(int i = 0; i<size; i++){
        printf("Enter a number: ");
        scanf("%d",&value);
        enqueue(&front, &rear, value);
    }
    printf("Enqueue:\n");
    printQueue(front);
    dequeue(&front, &rear);
    printf("\nDequeue:\n");
    printQueue(front);


    return 0;
}