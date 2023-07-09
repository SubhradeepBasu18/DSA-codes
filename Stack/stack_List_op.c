#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *top = NULL;
void push(int val)
{
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("Stack Overflow\n");
        return;
    }
    else{
        temp->data = val;
        temp->next = top;
        top = temp;
    }
}
void pop()
{
    if(top==NULL)
    {
        printf("Stack Underflow\n");
    }
    else{
        struct node * temp;
        temp = top;
        top = top->next;
        free(temp);
    }
}
int peek()
{
    if(top==NULL)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else{
        return top->data;
    }
}
void display()
{
    if(top==NULL)
    {
        printf("Stack Underflow\n");
    }
    else{
        struct node * temp;
        temp = top;
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp = temp->next;
        }
    }
}
int main()
{
    int choice,n;
    while (1)
    {
        printf("\n");
        printf("Enter 1 to Push\n");
        printf("Enter 2 to Pop\n");
        printf("Enter 3 to Peek\n");
        printf("Enter 4 to Display elements of the stack\n");
        printf("Enter 5 to Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter the item to be pushed: ");
                scanf("%d", &n);
                push(n);
                break;

            case 2:
                pop();
                break;

            case 3:
                printf("ITEM AT THE TOP",peek());
                break;

            case 4:
                display();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}