#include <stdio.h>
#include <stdlib.h>
struct Node
{
int data;
struct Node * next;
};
void swap_dat(struct Node * a, struct Node * b)
{
int temp = a->data;
a->data = b->data;
b->data = temp;
}
void swap_ad(struct Node * a, struct Node * b)
{
struct Node * temp = a->next;
a->next = b->next;
b->next = temp;
}
int main()
{
struct Node * head;
struct Node * second;
struct Node * third;
head = (struct Node *)malloc(sizeof(struct Node));
second = (struct Node *)malloc(sizeof(struct Node));
third = (struct Node *)malloc(sizeof(struct Node));
head->data = 1;
head->next = second;
second->data = 2;
second->next = third;
third->data = 3;
third->next = NULL;
printf("Before swapping: \n");
printf("%d %d %d\n", head->data, second->data, third->data);
//swap_dat(head, second);
//swap_ad(head,second);
swap_ad(second, third);
//swap_dat(second, third);
printf("After swapping: \n");
printf("%d %d %d\n", head->data, second->data, third->data);
return 0;
}