#include <stdio.h>
#include <stdlib.h>

typedef struct CircularQueue
{
    int size;
    int front;
    int rear;
    int *arr;
} queue;

int isEmpty(queue *q)
{
    if (q->front == q->rear)
        return 1;

    return 0;
}

int isFull(queue *q)
{
    if (((q->rear + 1) % (q->size)) == q->front)
        return 1;

    return 0;
}

void enqueue(queue *q, int data)
{
    if (isFull(q))
        exit(1);

    q->rear = ((q->rear + 1) % (q->size));
    q->arr[q->rear] = data;
}

int dequeue(queue *q)
{
    int val = -1;

    if (isEmpty(q))
        exit(1);

    q->front = ((q->front + 1) % (q->size));
    val = q->arr[q->front];

    return val;
}

int main()
{
    // Test Case : ChatGPT generated

    queue q;
    q.size = 5;              // total capacity
    q.front = q.rear = 0;    // initialize
    q.arr = (int *)malloc(q.size * sizeof(int));

    // Enqueue elements
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    // Dequeue elements
    printf("Dequeued: %d\n", dequeue(&q)); // should print 10
    printf("Dequeued: %d\n", dequeue(&q)); // should print 20

    // Enqueue more to test circular behavior
    enqueue(&q, 40);
    enqueue(&q, 50);

    // Dequeue remaining
    printf("Dequeued: %d\n", dequeue(&q)); // should print 30
    printf("Dequeued: %d\n", dequeue(&q)); // should print 40
    printf("Dequeued: %d\n", dequeue(&q)); // should print 50

    free(q.arr);

    return 0;
}