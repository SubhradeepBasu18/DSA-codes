#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int val)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = val;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void reOrder(struct node *root)
{
    if(root==NULL) return;
    int child=0;

    if(root->left) child+=root->left->data;
    if(root->right) child+=root->right->data;

    if(child>=root->data) root->data=child;
    else
    {
        if(root->left) root->left->data = root->data;
        else if(root->right) root->right->data = root->data;
    }
    reOrder(root->left);
    reOrder(root->right);

    int total=0;
    if(root->left) total+=root->left->data;
    if(root->right) total+=root->right->data;
    if(root->left || root->right) root->data = total;
}
void inOrder(struct node *root)
{
    if(root==NULL) return;
    inOrder(root->left);
    printf("%d ",root->data);
    inOrder(root->right);
}
int main()
{
    struct node *root = createNode(35);
    root->left = createNode(9);
    root->right = createNode(10);
    root->left->left = createNode(43);
    root->left->right = createNode(14);
    root->right->left = createNode(7);
    root->right->right = createNode(9);
    
    inOrder(root);
    printf("\n");
    reOrder(root);
    inOrder(root);
    
    return 0;
}
