#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int val) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void rightView(struct node *root, int res[], int *size,int level)
{
    if(root==NULL)
    return;

    if(*size==level)
    {
        res[*size] = root->data;
        (*size)++;
    }
    rightView(root->right,res,size,level+1);
    rightView(root->left,res,size,level+1);
}

void leftView(struct node *root, int res[], int *size, int level)
{
    if(root==NULL) return;
    
    if(*size==level)
    {
        res[*size] = root->data;
        (*size)++;
    }
    leftView(root->left,res,size,level+1);
    leftView(root->right,res,size,level+1);
}

int main() {
    struct node *root = createNode(4);
    root->left = createNode(2);
    root->right = createNode(6);
    root->left->left = createNode(1);
    root->left->right = createNode(3);

    int res[100];
    int size=0;
    // rightView(root,res,&size,0);
    leftView(root,res,&size,0);
    for(int i=0;i<size;i++)
    {
        printf("%d ",res[i]);
    }
    
    return 0;
}
