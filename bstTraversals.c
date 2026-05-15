#include <stdio.h>
#include <stdlib.h>

#define SIZE 5;

typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
}Node;


void bstTraversals(Node **root, int value){
    if(*root==NULL){
        Node *newNode = malloc(sizeof(Node));
        newNode->data=value;
        newNode->left=NULL;
        newNode->right=NULL;

        *root = newNode;
        return;
    }
    if(value<(*root)->data){
        bstTraversals(&((*root)->left),value);
    }else{
        bstTraversals(&((*root)->right),value);
    }
}

void inorder(Node *root){
    if(root==NULL){
        return;
    }

    inorder(root->left);

    printf("%d\n",root->data);

    inorder(root->right);

}
void Preorder(Node *root){
    if(root == NULL)
    {
        return;
    }
    printf("%d\n", root->data);
    Preorder(root->left);
    Preorder(root->right);
}

void Postorder(Node *root){
    if(root == NULL)
    {
        return;
    }
    Postorder(root->left);
    Postorder(root->right);
    printf("%d\n", root->data);
}

int main(){
    Node *root = NULL;



    bstTraversals(&root,10);
    bstTraversals(&root,5);
    bstTraversals(&root,3);
    bstTraversals(&root,7);
    bstTraversals(&root,20);
    //inorder(root);
    //Preorder(root);
    Postorder(root);

    return 0;
}