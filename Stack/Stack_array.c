#include <stdio.h>
#include <stdlib.h>
#define max 10
int stack[max];
int top=-1;
void push(int n)
{
    if(top==max-1)
    {
        printf("Stack overflow\n");
    }
    else
    {
    top = top+1;
    stack[top] = n;
    }
}
void pop()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else{
    int item;
    item = stack[top];
    top = top-1;
    printf("THE ITEM POPPED IS: %d",item);
    }
}
void peek()
{
   if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("The top element is: %d\n", stack[top]);
    };
}
void display()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Elements of the stack are: ");
        for (int i = top; i >= 0; i--)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
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
                peek();
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

}
