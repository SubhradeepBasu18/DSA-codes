#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node * left;
    struct node * right;
};
struct node * createNode(int key)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->data = key;
    p->left = NULL;
    p->right = NULL;
    return p;
}
void inOrder(struct node *root)
{
    if(root!=NULL)
    {
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}
struct node *iPredecessor(struct node *root)
{
    root = root->left;
    while(root->right!=NULL)
    {
        root = root->right;
    }
    return root;
}
struct node *deleteNode(struct node *root, int key)
{
    struct node *iPre;
    if(root==NULL)
    {
        return NULL;
    }
    if(root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }
    if(root->data > key)
    {
        root->left = deleteNode(root->left,key);
    }
    else if(root->data < key)
    {
        root->right = deleteNode(root->right,key);
    }
    else
    {
        iPre = iPredecessor(root);
        root->data = iPre->data;
        root->left = deleteNode(root->left, iPre->data);
    }
    return root;
}
int main()
{
    struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);
    struct node *p5 = createNode(0);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p3->left = p5;

    inOrder(p);
    printf("\n");
    deleteNode(p,5);
    inOrder(p);
    return 0;
}