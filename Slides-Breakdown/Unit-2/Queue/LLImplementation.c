#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

void enqueue(node **front, node **rear, int data)
{
    node *temp = (node*)malloc(sizeof(node));

    if (temp == NULL) exit(1);

    temp->data = data;
    temp->next = NULL;

    if (*front == NULL) *front = *rear = temp;

    else{
        (*rear)->next = temp;
        *rear = temp;
    }

};

int dequeue(node **front, node **rear)
{
    int val = -1;
    if (*front == NULL) exit(1);

    node *ptr = *front;
    *front = (*front)->next;
    val = ptr->data;

    free(ptr);

    return val;
};

void printQueue(node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    node *front = NULL;
    node *rear = NULL;

    // Test Case : CHATGPT generated

    printf("Enqueueing 10, 20, 30...\n");
    enqueue(&front, &rear, 10);
    enqueue(&front, &rear, 20);
    enqueue(&front, &rear, 30);

    printf("Queue after enqueues: ");
    printQueue(front);   // expected: 10 20 30
    printf("\n");

    printf("Dequeue -> %d\n", dequeue(&front, &rear)); // expected: 10
    printf("Queue now: ");
    printQueue(front);   // expected: 20 30
    printf("\n");

    printf("Enqueueing 40...\n");
    enqueue(&front, &rear, 40);
    printf("Queue now: ");
    printQueue(front);   // expected: 20 30 40
    printf("\n");

    printf("Dequeue -> %d\n", dequeue(&front, &rear)); // expected: 20
    printf("Dequeue -> %d\n", dequeue(&front, &rear)); // expected: 30
    printf("Queue now: ");
    printQueue(front);   // expected: 40
    printf("\n");

    printf("Dequeue -> %d\n", dequeue(&front, &rear)); // expected: 40
    printf("Queue now: ");
    printQueue(front);   // expected: (empty)
    printf("\n");

    return 0;
}