#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
} Node;


/*
    Simple Binary Search Tree insertion using recursion.

    Logic:
    - If current position is NULL -> create node
    - Smaller values go left
    - Bigger values go right
*/

void initTree(Node **root, int value)
{
    // Empty position found
    if(*root == NULL)
    {
        Node *newNode = malloc(sizeof(Node));

        newNode->data = value;
        newNode->left = NULL;
        newNode->right = NULL;

        *root = newNode;

        return;
    }

    // Go left
    if(value < (*root)->data)
    {
        initTree(&((*root)->left), value);
    }

    // Go right
    else
    {
        initTree(&((*root)->right), value);
    }
}


/*
    Inorder traversal:
    left -> root -> right
*/

void inorder(Node *root)
{
    if(root == NULL)
    {
        return;
    }

    inorder(root->left);

    printf("%d ", root->data);

    inorder(root->right);
}

void destroyTree(Node **root){
    if (*root==NULL){ return;}
    destroyTree(&((*root)->left));
    destroyTree(&((*root)->right));
    free(*root);
    root = NULL;
}


int main()
{
    int size;
    int value;

    Node *root = NULL;

    printf("Enter size of your tree: ");
    scanf("%d", &size);

    for(int i = 0; i < size; i++)
    {
        printf("Enter a number: ");
        scanf("%d", &value);

        initTree(&root, value);
    }

    printf("\nInorder traversal:\n");

    inorder(root);

    return 0;
}