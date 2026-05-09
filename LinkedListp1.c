#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
} Node;

int main(){

    printf("How many nodes? ");
    int size;
    scanf("%d", &size);

    Node *head = NULL;
    Node *current = NULL;

    for(int i = 0; i < size; i++){

        Node *newNode;
        newNode = malloc(sizeof(Node));

        printf("Enter value: ");
        scanf("%d", &newNode->data);

        newNode->next = NULL;

        if(head == NULL){
            head = newNode;
            current = newNode;
        }else{
            current->next = newNode;
            current = newNode;
        }
    }

    current = head;

    while(current != NULL){
        printf("%d\n", current->data);
        current = current->next;
    }

    current = head;

    while(current != NULL){
        Node *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}