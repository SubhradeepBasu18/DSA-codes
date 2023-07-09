#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node * prevNode;
    struct Node * next;
};
void printLinkedlist(struct Node * head)
{
    struct Node * p = head;
    while(p!=NULL)
    {
        printf("%d\n",p->data);
        p=p->next;
    }

}
void printLinkedlistRev(struct Node * head)
{
    struct Node * p = head;
    while(p!=NULL)
    {
        printf("%d\n",p->data);
        p=p->prevNode;
    }
}
int main()
{
    struct Node * head;
    struct Node * second;
    struct Node * third;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 7;
    head->next = second;
    head->prevNode = NULL;

    second->data = 11;
    second->next = third;
    second->prevNode = head;

    third->data = 21;
    third->next = NULL;
    third->prevNode = second;

    //printLinkedlist(head);
    printLinkedlistRev(third);
    return 0;
}