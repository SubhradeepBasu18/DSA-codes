#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
    int height;
};
struct node * createNode(int data)
{
    struct node * n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    n->height = 1;
    return n;
}
void inOrder(struct node *node)
{
    if(node!=NULL)
    {
        inOrder(node->left);
        printf("%d ",node->data);
        inOrder(node->right);
    }
}
int max(int a, int b)
{
    return (a>b)?a:b;
}
int getHeight(struct node *n)
{
    if(n==NULL)
    {
        return 1;
    }
    return n->height;
}
int bfFactor(struct node* n)
{
    if(n==NULL)
    {
        return 0;
    }
    return(getHeight(n->left) - getHeight(n->right));
}
struct node* leftRotate(struct node* x)
{
    struct node* y = x->right;
    struct node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1+max(getHeight(x->right),getHeight(x->left));
    y->height = 1+max(getHeight(y->right),getHeight(y->left));

    return y;
}
struct node* rightRotate(struct node* y)
{
    struct node* x = y->left;
    struct node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1+max(getHeight(y->right),getHeight(y->left));
    x->height = 1+max(getHeight(x->right),getHeight(x->left));
    return x;
}

struct node* insert(struct node* node, int key)
{
    if(node==NULL)
    {
        return createNode(key);
    }
    if(key < node->data)
    {
        node->left = insert(node->left,key);
    }
    else if(key > node->data)
    {
        node->right = insert(node->right,key);
    }
    node->height = 1+max(getHeight(node->left),getHeight(node->right));
    int bf = bfFactor(node);

    if(bf>1 && key < node->left->data)
    {
        return rightRotate(node);
    }
    if(bf<-1 && key > node->right->data)
    {
        return leftRotate(node);
    }
    if(bf>1 && key>node->left->data)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if(bf<-1 && key<node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}
int main()
{
    struct node *root = NULL;
    root = insert(root,1);
    root = insert(root,2);
    root = insert(root,4);
    // root = insert(root,5);
    // root = insert(root,6);
    // root = insert(root,3);   
    inOrder(root);
    return 0;
}
