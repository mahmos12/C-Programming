#include <stdio.h>
#include <stdlib.h>

/*
Stack implementation using Linked List in C

- Uses dynamic memory allocation with malloc
- Implements stack operations: push, pop, and print
- Demonstrates LIFO (Last In First Out) behavior
- Uses pointers, double pointers, structs, and linked list traversal
- Frees memory properly to avoid memory leaks
*/

typedef struct Node
{
    int front;
    struct Node *next;
} Node;

void push(Node **top, int value)
{
    Node *newNode;
    newNode = malloc(sizeof(Node));

    newNode->front = value;
    newNode->next = *top;
    *top = newNode;
}

void pop(Node **top)
{
    if (*top != NULL)
    {
        Node *temp = *top;
        *top = (*top)->next;
        free(temp);
    }
}

void printStack(Node *top)
{
    Node *temp = top;

    while (temp != NULL)
    {
        printf("%d\t", temp->front);
        temp = temp->next;
    }
}

int main()
{
    int size;
    printf("How many Number? ");
    scanf("%d", &size);
    int value;
    Node *top = NULL;

    for (int i = 0; i < size; i++)
    {
        printf("Enter a number: ");
        scanf("%d", &value);
        push(&top, value);
    }
    printf("Push:\t");
    printStack(top);
    printf("\nPop\n");

    for (int i = 0; i < size; i++)
    {
        pop(&top);
        printf("\n");
        printStack(top);
    }

    return 0;
}