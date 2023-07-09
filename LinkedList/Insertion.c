#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node * next;
};
struct Node * InsertAtBegin(struct Node * head, int value)
{
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next=head;
    ptr->data=value;
    head = ptr;
    return head;
}
struct Node * InsertAtIndex(struct Node * head, int value, int index)
{
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node * p = head;
    int i=0;
    while(i!=index-1)
    {
        p=p->next;
        i++;
    }
    ptr->data = value;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}
struct Node * InsertAtEnd(struct Node * head, int value)
{
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node * p = head;
    ptr->data=value;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;
    return head;
}
struct Node * InsertAfterNode(struct Node * head, struct Node * prevNode, int value)
{
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data=value;
    ptr->next=prevNode->next;
    prevNode->next=ptr;
    return head;
}
void printLinkedList(struct Node *p)
{
    while(p!=NULL)
    {
        printf("%d\n",p->data);
        p=p->next;

    }
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
    //head = InsertAtBegin(head,66);
    //head = InsertAtIndex(head,21,1);
    //InsertAtEnd(head,100);
    head = InsertAfterNode(head,head,21);
    printf("\n");
    printLinkedList(head);
    
    return 0;
}
