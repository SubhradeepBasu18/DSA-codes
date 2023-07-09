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
int height(struct node * root)
{
    if(root==NULL)
    {
        return 0;
    }
    int l_child = height(root->left);
    int r_child = height(root->right);
    if(l_child>r_child)
    {
        return l_child+1;
    }
    else
    {
        return r_child+1;
    }
}
int max_child(struct node *root)
{
    if(root==NULL)
    {
        return -1;
    }
    else if(root->right==NULL)
    {
        return root->data;
    }
    else
    {
        return max_child(root->right);
    }
    
}
int min_child(struct node *root)
{
    if(root==NULL)
    {
        return -1;
    }
    else if(root->left==NULL)
    {
        return root->data;
    }
    else
    {
        return min_child(root->left);
    }
}
int depth(struct node *p)
{
    if(p==NULL)
    {
        return -1;
    }
    int l_child = depth(p->left);
    int r_child = depth(p->right);
    if(l_child>r_child)
    {
        return l_child+1;
    }
    else
    {
        return r_child+1;
    }
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

    printf("Height of the tree is: %d\n",height(p));
    printf("Max element in the tree is: %d\n",max_child(p));
    printf("Min element in the tree is: %d\n",min_child(p));
    printf("The depth of the node %d is: %d",p1->data,depth(p1));
    return 0;
}
