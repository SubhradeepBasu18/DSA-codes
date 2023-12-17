#include <stdio.h>
#include <stdlib.h>

// Node definition
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Queue Node
struct QueueNode {
    struct Node *node;
    int line;
};

// Queue definition
struct Queue {
    struct QueueNode *array;
    int front, rear;
    unsigned capacity;
};
struct Node * createNode(int data){
    struct Node * node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
// Create a new queue
struct Queue *createQueue(unsigned capacity) {
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = 0;
    queue->array = (struct QueueNode *)malloc(queue->capacity * sizeof(struct QueueNode));
    return queue;
}

// Check if the queue is empty
int isEmpty(struct Queue *queue) {
    return (queue->front == queue->rear);
}

// Enqueue an element to the queue
void enqueue(struct Queue *queue, struct Node *node, int line) {
    queue->array[queue->rear].node = node;
    queue->array[queue->rear].line = line;
    queue->rear++;
}

// Dequeue an element from the queue
struct QueueNode dequeue(struct Queue *queue) {
    if (isEmpty(queue)) {
        struct QueueNode empty = {NULL, 0};
        return empty;
    }
    return queue->array[queue->front++];
}

// Function to get top view of a binary tree
int *topView(struct Node *root, int *size) {
    if (root == NULL) {
        *size = 0;
        return NULL;
    }

    int *ans = (int *)malloc(sizeof(int) * 1000);
    struct Queue *q = createQueue(1000);
    *size = 0;
    int min_line = 0, max_line = 0;

    enqueue(q, root, 0);

    // Hash map to store the first node encountered at each line
    struct Node *mpp[1000] = {NULL};

    while (!isEmpty(q)) {
        struct QueueNode it = dequeue(q);
        struct Node *node = it.node;
        int line = it.line;

        if (line < min_line) {
            min_line = line;
        } else if (line > max_line) {
            max_line = line;
        }

        // Store the first node encountered at each line
        if (mpp[line + 500] == NULL) { // Shift line index to avoid negative indices
            mpp[line + 500] = node;
        }

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


// Example usage
int main() {
    // Creating nodes for a sample binary tree
    struct Node * root = createNode(4);
    root->left = createNode(2);
    root->right = createNode(6);
    root->left->left = createNode(1);
    root->left->right = createNode(3);
    int size;
    int *result = topView(root, &size);

    printf("Top View of the Binary Tree: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    free(root->right->left);
    free(root->right);
    free(root->left->right);
    free(root->left);
    free(root);

    return 0;
}
