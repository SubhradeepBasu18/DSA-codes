#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node * left;
    struct Node * right;
};
struct Node * createNode(int key)
{
    struct Node * n = (struct Node *)malloc(sizeof(struct Node));
    n->data = key;
    n->left = NULL;
    n->right = NULL;
    return n;
}
void inOrder(struct Node * root)
{
    if(root!=NULL)
    {
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}
void insert(struct Node * root, int key)
{
    struct Node * prev = NULL;
    while(root!=NULL)
    {
        prev = root;
        if(key==root->data)
        {
            printf("Element %d already exist. Can not be inserted \n",key);
            return;
        }
        else if(key>root->data)
        {
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    struct Node * new = createNode(key);
    if(prev->data > key)
    {
        prev->left = new;
    }
    else
    {
        prev->right = new;
    }
}
int main()
{
    struct Node * p = createNode(10);
    struct Node * p1 = createNode(11);
    struct Node * p2 = createNode(8);
    struct Node * p3 = createNode(1);

    // Linking the nodes
    p->left = p2;
    p->right = p1;
    p2->left = p3;

    // 10
    // / \
    // 8 11
    // /
    // 1
    insert(p,9);
    printf("%d",p->left->right->data);
    //inOrder(p);
    return 0;
}