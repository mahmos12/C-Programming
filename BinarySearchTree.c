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



void BinarySerach(Node *root, int value){
    if(root==NULL){ return;}
    if(root->data==value){
        printf("finde : %d",root->data);
    }else if(value < root->data){
        BinarySerach(root->left,value);
    }else{
        BinarySerach(root->right,value);      
    }
}

int main(){
    Node *root = NULL;

    bstTraversals(&root,10);
    bstTraversals(&root,5);
    bstTraversals(&root,3);
    bstTraversals(&root,7);
    bstTraversals(&root,20);
    BinarySerach(root,7);

    return 0;
}