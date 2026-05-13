#include <stdio.h>
#include <stdlib.h>

/*
    Simple Doubly Linked List implementation.
    Features:
    - Insert node at end
    - Remove node from end
    - Forward traversal

    Concepts practiced:
    - Dynamic memory allocation
    - Double pointers (Node**)
    - prev/next pointer management
    - Tail movement
    - Memory cleanup with free()
*/

typedef struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
}Node;


void insertEnd(Node **head, Node **tail, int value){
    Node *newNode;
    newNode = malloc(sizeof(Node));
    newNode->data=value;
    newNode->next=NULL;
    newNode->prev=NULL;

    if(*head==NULL){
        *head=newNode;
        *tail = newNode;
    }else{
        (*tail)->next =  newNode;
        newNode->prev=*tail;
        *tail=newNode;
    }
}

void printList(Node *head){
    Node *temp;
    temp = head;
    while (temp!=NULL){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
}


void removeFromEnd(Node **head, Node **tail){
    if (*tail == NULL){
        printf("List is empty!");
        return;
    }
    Node *temp = *tail;
    if ((*tail)->prev == NULL){
        *head = NULL;
        *tail = NULL;
        free(temp);
    }else{
        *tail = (*tail)->prev;
        (*tail)->next = NULL;
        free(temp);
    }
}





int main(){
    Node *head =NULL;
    Node *tail = NULL;
    int size;
    int value;
    printf("Enter size of your list! ");
    scanf("%d",&size);

    for(int i= 0; i<size; i++){
        printf("Enter a number: ");
        scanf("%d",&value);
        insertEnd(&head,&tail,value);
    }
    printList(head);
    printf("\n");
    removeFromEnd(&head,&tail);
    printList(head);

    return 0;
}