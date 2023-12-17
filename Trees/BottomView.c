/*Logic is same as of Top View, the only difference is the node is not checked before 
adding to the map*/
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct QueueNode{
    struct node *node;
    int line;
};

struct Queue{
    struct QueueNode *arr;
    int front, rear;
    unsigned capacity;
};

struct node *createNode(int val)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Queue *createQueue(unsigned capacity)
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = 0;
    queue->arr = (struct QueueNode *)malloc(queue->capacity * sizeof(struct QueueNode));
    return queue;
}

int isEmpty(struct Queue *queue)
{
    return (queue->front == queue->rear);
}

void enqueue(struct Queue *queue, struct node *node, int line)
{
    queue->arr[queue->rear].node = node;
    queue->arr[queue->rear].line = line;
    queue->rear++;
}

struct QueueNode dequeue(struct Queue *queue)
{
    if(isEmpty(queue))
    {
        struct QueueNode empty = {NULL, 0};
        return empty;
    }
    return queue->arr[queue->front++];
}

int *bottomView(struct node *root, int *size)
{
     if (root == NULL) {
        *size = 0;
        return NULL;
    }

    int *ans = (int *)malloc(sizeof(int) * 1000);
    struct Queue *q = createQueue(1000);
    *size = 0;
    int min_line = 0, max_line = 0;

    enqueue(q, root, 0);

    struct node *mpp[1000] = {NULL};

    while (!isEmpty(q)) {
        struct QueueNode it = dequeue(q);
        struct node *node = it.node;
        int line = it.line;

        if (line < min_line) {
            min_line = line;
        } else if (line > max_line) {
            max_line = line;
        }

        // Store the first node encountered at each line
        mpp[line + 500] = node;

        if (node->left != NULL) {
            enqueue(q, node->left, line - 1);
        }
        if (node->right != NULL) {
            enqueue(q, node->right, line + 1);
        }
    }

    // Retrieve nodes in order from leftmost to rightmost line
    for (int line = min_line; line <= max_line; line++) {
        if (mpp[line + 500] != NULL) {
            ans[*size] = mpp[line + 500]->data;
            (*size)++;
        }
    }

    return ans;

}

int main()
{
    struct node * root = createNode(4);
    root->left = createNode(2);
    root->right = createNode(6);
    root->left->left = createNode(1);
    root->left->right = createNode(3);
    int size;
    int *result = bottomView(root, &size);

    printf("Top View of the Binary Tree: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    return 0;
}
