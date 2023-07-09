#include <stdio.h>
#include <stdlib.h>
struct Queue
{
    int data;
    struct Queue * next;
};
struct Queue * f = NULL;
struct Queue * r = NULL;
void enqueue(int val)
{
    struct Queue * q = (struct Queue *)malloc(sizeof(struct Queue));
    if(q == NULL)
    {
        printf("Queue is Full\n");
    }

    q->data = val;
    q->next = NULL;
    if(f==NULL)
    {
        f=r=q;
    }
    else
    {
        r->next = q;
        r = q;
    }
}
int dequeue()
{
    if (f == NULL)
    {
        printf("Queue is Empty\n");
        return -1;
    }
    struct Queue * q = f;
    int val; 
    val = q->data;
    f = f->next;
    free(q); 
    return val;
}
void Traversal(struct Queue * ptr)
{
    printf("Printing the Queue now.....\n");
    while(ptr!=NULL)
    {
        printf("%d\n",ptr->data);
        ptr = ptr->next;
    }
}
int main()
{
    enqueue(2);
    enqueue(4);
    Traversal(f);
    int d = dequeue();
    printf("The dequeued element is: %d\n",d);
    Traversal(f);
    return 0;
}