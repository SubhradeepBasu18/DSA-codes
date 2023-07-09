#include <stdio.h>
#include <stdlib.h>
struct queue{
int size;
int *a;
};
int f = -1;
int r = -1;
int isFull(struct queue * q)
{
    if((f==0 && r==q->size-1) || (f==r+1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isEmpty()
{
    if(f==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void enqueue(struct queue *q,int x)
{
    // struct queue * q = (struct queue *)malloc(sizeof(struct queue));
    if(isFull(q))
    {
        printf("QUEUE IS FULL");
        return;
    }
    if(f==-1)
    {
        f=0;
    }
    if(r==q->size-1)
    {
        r=0;
    }
    else
    {
        r=r+1;
    }
    q->a[r] = x;
}
int dequeue(struct queue *q)
{
    if(isEmpty())
    {
        printf("QUEUE IS EMPTY");
        return -1;
    }
    int x = q->a[f];
    if(f==r)
    {
        f=-1;
        r=-1;
    }
    else if(f==q->size-1)
    {
        f=0;
    }
    else
    {
        f=f+1;
    }
    return x;
}
void Traverse(struct queue *q)
{
    if(isEmpty())
    {
        printf("QUEUE IS EMPTY");
    }
    else
    {
        int i=f;
        while(i!=r)
        {
            printf("INDEX = %d\t",i);
            printf("%d\n",q->a[i]);
            i=(i+1)%q->size;
        }
        printf("INDEX = %d\t",i);
        printf("%d\n",q->a[i]);
    }
}
int main()
{
    struct queue * q = (struct queue * )malloc(sizeof(struct queue));
    q->size = 5;
    q->a = (int *)malloc(q->size * sizeof(int));
    enqueue(q,10);
    enqueue(q,20);
    enqueue(q,30);
    enqueue(q,40);
    enqueue(q,50);
    //Traverse(q);
    //printf("The dequeued element is: %d\n",dequeue(q));
    //Traverse(q);
    dequeue(q);
    dequeue(q);
    enqueue(q,100);
    // dequeue(q);
    // dequeue(q);
    // dequeue(q);
    // enqueue(q,10);
    Traverse(q);
    free(q->a);
    free(q);
    return 0;
}