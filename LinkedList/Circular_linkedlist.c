#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node * next;
};
void printLinkedList(struct Node * head)
{
    struct Node * p = head;
    do
    {
        printf("The Element is: %d\n",p->data);
        p=p->next;
    } while (p!=head);
    
}
struct Node * InsertAtBegin(struct Node * head, int value)
{
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = value;
    struct Node * p = head->next;
    while(p->next!=head)
    {
        p=p->next;
    }
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}
struct Node * InsertAtEnd(struct Node * head, int value)
{
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = value;
    struct Node * p = head->next;
    while(p->next!=head)
    {
        p=p->next;
    }
    p->next = ptr;
    ptr->next = head;
    return head;
}
struct Node * DeleteFromBegin(struct Node * head)
{
   struct Node * p = head->next; 
    struct Node * q = head;
    while (p!= head)
    {
        p = p->next;
        q = q->next;
    }
    q->next = head->next;
    free(head);
    return q->next;

}
int main()
{
    struct Node * head;
    struct Node * second;
    struct Node * third;
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third =  (struct Node *)malloc(sizeof(struct Node));

    head->data = 7;
    head->next = second;

    second->data = 8;
    second->next = third;

    third->data = 11;
    third->next = head;

    printLinkedList(head);
    printf("\n");

    //head = InsertAtBegin(head,21);
    //head = InsertAtEnd(head,21);
    head = DeleteFromBegin(head);
    printLinkedList(head);
    return 0;
}