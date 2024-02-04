//circular queue
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *front = NULL;
struct node *rear = NULL;
int size=0;

struct node *createNode(int val){
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->data = val;
    p->next = NULL;
    return p;
}

void enqueue(int x,int n){
    struct node *p = createNode(x);
    if(n==size) printf("Queue is full\n");
    else
    {
        if(!front){
            front=rear=p;
            rear->next=front;
        }
        else{
            rear->next=p;
            rear=p;
            rear->next=front;
        }
        size++;
    }
}
int dequeue(int n){
    if(size==0) printf("Queue is empty\n");
    else
    {
        if(!front) return -1;
        int x = front->data;
        struct node *p = front;
        if(front==rear){
            front=rear=NULL;
        }
        else{
            front=front->next;
            rear->next=front;
        }
        size--;
        free(p);
        return x;
    }
}
void display(){
    if(!front) {
        printf("Queue is empty\n");
        return;
    }
    struct node *p = front;
    while(p->next!=front){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("%d ",p->data);
    printf("\n");
}

int main()
{
    int n;
    printf("Enter the size: ");
    scanf("%d", &n);

    printf("1 -> Enqueue\n2 -> Dequeue\n3 -> Display\n4 -> Exit\n");
    while(1) {
        int choice, x;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value to be enqueued: ");
                scanf("%d", &x);
                enqueue(x,n);
                
                break;
            case 2:
                printf("%d\n",dequeue(n));
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
