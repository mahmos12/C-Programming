#include <stdio.h>
#include <stdlib.h>

/*
Dynamic Singly Linked List in C

- Creates a linked list dynamically using malloc
- Stores integer values inside nodes
- Links nodes together using pointers
- Traverses the list and prints all values
- Frees allocated memory to avoid memory leaks
- Demonstrates structs, self-referential pointers, dynamic memory allocation, traversal, and linked list management
*/

typedef struct Node
{
    int front;
    struct Node *next;
} Node;

int main()
{

    int nodeSize;
    Node *newNode;
    Node *head = NULL;
    Node *current;

    printf("How many nodes? ");
    scanf("%d", &nodeSize);

    for (int i = 0; i < nodeSize; i++)
    {
        newNode = malloc(sizeof(Node));

        printf("Enter value: ");
        scanf("%d", &newNode->front);
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            current = newNode;
        }
        else
        {
            current->next = newNode;
            current = newNode;
        }
    }

    current = head;
    while (current != NULL)
    {
        printf("%d\t", current->front);
        Node *temp = current;
        current = current->next;

        free(temp);
    }
    return 0;
}
