#include <stdio.h>
#include <stdlib.h>

struct Queue{
    int size;
    int f;
    int r;
    int *a;
};
int isFull(struct Queue *q)
{
    if(q->r==q->size-1)
    {
        return 1;
    }
    else{
        return 0;
    }
}
int isEmpty(struct Queue *q)
{
    if(q->f==q->r)
    {
        return 1;
    }
    else{
        return 0;
    }
}
void enqueue(struct Queue * q,int value)
{
    if(isFull(q))
    {
        printf("Queue Overflow\n");
        return;
    }
    else{
        if(q->f==-1)
        {
            q->f=0;
        }
        q->r++;
        q->a[q->r] = value;
    }
}
int dequeue(struct Queue *q)
{
    if(isEmpty(q))
    {
        printf("Queue Underflow\n");
    }
    else{
        int x = q->a[q->f];
        q->f++;
        return x;
    }
}
void display(struct Queue *q)
{    
    for(int i=q->f;i<=q->r;i++)
    {
        printf("INDEX = %d\t",i);
        printf("%d\n ",q->a[i]);
    }
}
int main()
{
    struct Queue *q;
    q->size = 5;
    q->f = -1;
    q->r = -1;
    q->a = (int *)malloc(q->size*sizeof(int));
    enqueue(q,2);
    enqueue(q,4);
    enqueue(q,6);
    enqueue(q,8);
    enqueue(q,10);
    //enqueue(q,12);
    // display(q);
    dequeue(q);
    dequeue(q);
    enqueue(q,100);
    display(q);
    return 0;
}
