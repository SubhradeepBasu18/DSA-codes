#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct stack
{
    int top;
    int size;
    struct node **st;
};
struct node * createNode(int data)
{
    struct node * n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}
int isFull(struct stack *s)
{
    if(s->top == s->size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isEmpty(struct stack *s)
{
    if(s->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(struct node *item, struct stack *s)
{
    if(isFull(s))
    {
        printf("Stack Overflow\n");
        return;
    }
    else
    {
        s->top++;
        s->st[s->top]=item;
        ///printf("PUSH SUCCESS!\n");
    }
}
struct node * pop(struct stack *s)
{
    if(isEmpty(s))
    {
        printf("Stack Underflow\n");
        return NULL;
    }
    else
    {
        struct node * item = s->st[s->top];;
        s->top--;
        return item;
    }

}
void preOrder(struct node * root, struct stack * s)
{
    struct node * p = root;
    if(p==NULL)
    {
        printf("Tree is empty\n");
        return;
    }
    push(p,s);
    while(!isEmpty(s))
    {
        p = pop(s);
        printf("%d ",p->data);
        if(p->right!=NULL)
        {
            push(p->right,s);
        }
        if(p->left!=NULL)
        {
            push(p->left,s);
        }
    }
}
int main()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->top = -1;
    s->size = 10;
    s->st = (struct node **)malloc(s->size*sizeof(struct node*));

    struct node * p = createNode(5);
    struct node * p1 = createNode(3);
    struct node * p2 = createNode(6);
    struct node * p3 = createNode(2);
    struct node * p4 = createNode(4);

    //Tree
    //    5
    //   / \
    //  3   6
    // / \
    // 2 4
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    preOrder(p,s);
    return 0;
}