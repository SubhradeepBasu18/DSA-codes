#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node * next;
};
void printLinkedList(struct Node * p)
{
    while(p!=NULL)
    {
        printf("%d\n",p->data);
        p=p->next;
    }
}
struct Node * DeleteFromBegin(struct Node * head)
{
    struct Node * ptr = head;
    head = head->next;
    free(ptr);
    return head;

}
struct Node * DeleteBetween(struct Node * head, int index)
{
    struct Node * p = head;
    struct Node * q = head->next;
    int i=0;
    while(i!=index-1)
    {
        p=p->next;
        q=q->next;
        i++;
    }
    p->next = q->next;
    free(q);
    return head;
}
struct Node * DeleteLast(struct Node * head)
{
    struct Node * p = head;
    struct Node * q = head->next;
    int i=0;
    while(q->next!=NULL)
    {
        p=p->next;
        q=q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}
struct Node * DeleteAt(struct Node * head, int value)
{
    struct Node * p = head;
    struct Node * q = head->next;
    int i=0;
    while(q->data!=value)
    {
        p=p->next;
        q=q->next;
    }
    p->next = q->next;
    free(q);
    return head;
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
    third->next = NULL;

    printLinkedList(head);
    printf("\n");
    // head = DeleteFromBegin(head);
    // head = DeleteBetween(head,1);
    // head = DeleteLast(head);
    head = DeleteAt(head,8);
    printLinkedList(head);
    return 0;
}