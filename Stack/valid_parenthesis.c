#include <stdio.h>
#include <stdlib.h>
struct Stack
{
    int top;
    int size;
    char *arr;
};
void push(struct Stack * sp, char ch)
{
    if(sp->top == sp->size-1)
    {
        printf("Stack Overflow");
    }
    else
    {
        sp->top++;
        sp->arr[sp->top] = ch;
    }
}
char pop(struct Stack * sp)
{
    if(sp->top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        char ch = sp->arr[sp->top];
        sp->top--;
        return ch;
    }
}
int isValidParenthesis(char * a)
{
    struct Stack * sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    for(int i=0;a[i]!='\0';i++)
    {
        if(a[i]=='(' || a[i]=='{' || a[i]=='[')
        {
            push(sp,a[i]);
        }
        else if(a[i]==')' || a[i]=='}' || a[i]==']')
        {
            if(sp->top == -1)
            {
                return 0;
            }
            else
            {
                char popped = pop(sp);
               if((a[i] == ')' && popped != '(')    ||
                  (a[i] == '}' && popped != '{')    ||
                  (a[i] == ']' && popped != '['))
                  {
                        return 0;
                  }
            }
        }
    }
    if(sp->top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    char * e = "{([)])}";
    if(isValidParenthesis(e))
    printf("Valid");
    else
    printf("Invalid");
    return 0;
}