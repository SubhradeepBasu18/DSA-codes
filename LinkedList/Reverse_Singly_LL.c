#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *createNode(int val){
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->data=val;
    p->next=NULL;
    return p;
}

struct node *reverse(struct node *head)
{
    struct node *temp = head;
    struct node *prev=NULL;
    while(temp!=NULL){
        struct node *front = temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }
    return prev;
}

struct node *Recur_reverse(struct node *head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    struct node *newNode = Recur_reverse(head->next);
    struct node *front = head->next;
    front->next=head;
    head->next=NULL;
    return newNode;
}

void display(struct node *head){
    struct node *p = head;
    while(p!=NULL){
        printf("%d\n",p->data);
        p=p->next;
    }
}
int main()
{
    struct node *head = createNode(10);
    struct node *second = createNode(20);
    struct node *third = createNode(30);
    head->next=second;
    second->next=third;
    
    printf("Given Linked List\n");
    display(head);
    // head = Recur_reverse(head);
    head = reverse(head);
    printf("Reversed Linked List\n");
    display(head);
    return 0;
}
