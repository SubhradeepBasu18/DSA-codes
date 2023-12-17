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

int isSymmetricalUtil(struct node *root1, struct node *root2)
{
    if(root1==NULL|| root2==NULL)
    return root1==root2;

    return (root1->data==root2->data) && isSymmetricalUtil(root1->left,root2->right) && isSymmetricalUtil(root1->right,root2->left);
}

int isSymmetrical(struct node *root)
{
    if(root==NULL)
    return 1;
    return isSymmetricalUtil(root->left,root->right);
}
int main()
{
    struct node *root = createNode(4);
    root->left = createNode(2);
    root->right = createNode(2);
    root->left->left = createNode(1);
    root->right->right = createNode(1);
    root->left->right = createNode(3);
    root->right->left = createNode(3);

    if(isSymmetrical(root))
    printf("Symmetrical");
    else
    printf("Not Symmetrical");
    return 0;
}
