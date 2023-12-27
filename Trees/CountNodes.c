//TC -> O(log N * logN)

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int val)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int leftHeight(struct node *curr)
{
    int height=0;
    while(curr!=NULL)
    {
        height++;
        curr = curr->left;
    }
    return height;
}

int rightHeight(struct node *curr)
{
    int height=0;
    while(curr!=NULL)
    {
        height++;
        curr = curr->right;
    }
    return height;
}

int countNodes(struct node *root)
{
    if(root==NULL) return 0;

    int lh = leftHeight(root);
    int rh = rightHeight(root);

    if(lh==rh) return (1<<lh)-1; //(1<<h) -> 2^lh

    int leftNodes = countNodes(root->left);
    int rightNodes = countNodes(root->right);

    return 1+leftNodes+rightNodes;
}

int main()
{
    struct node *root = createNode(4);
    root->left = createNode(2);
    root->right = createNode(6);
    root->left->left = createNode(1);
    root->left->right = createNode(3);    

    printf("Total Nodes: %d\n", countNodes(root));
    return 0;
}
