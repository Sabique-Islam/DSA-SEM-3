#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct
{
    int front;
    int rear;
    int size;
    int *arr;
} queue;

void init(queue **q)
{
    *q = (queue*)malloc(sizeof(queue));
    (*q)->size = MAX_SIZE;
    (*q)->arr = (int*)malloc(((*q)->size)*sizeof(int));

    (*q)->front = -1;
    (*q)->rear = -1;
}

int isFull(queue *q)
{
    return (((q->rear + 1) % (q->size)) == q->front);
}

int isEmpty(queue *q)
{
    return q->front == -1;
}

void enqueueFront(queue *q, int data)
{
    if (isFull(q))
        return;
    
    if (isEmpty(q))
    {
        q->rear = q->front = 0;
    } 
    else 
    {
        q->front = (q->front - 1) % q->size;
    }

    q->arr[q->front] = data;
}

void enqueueRear(queue *q, int data)
{
    if (isFull(q))
        return;
    
    if (isEmpty(q))
    {
        q->rear = q->front = 0;
    } 
    else 
    {
        q->rear = (q->rear + 1) % q->size;
    }

    q->arr[q->rear] = data;
}

void dequeueFront(queue *q)
{
    if (isEmpty(q))
        return;

    if (q->front == q->rear)
        q->front = q->rear = -1;
    else    
        q->front = (q->front + 1) % q->size;
}

void dequeueRear(queue *q)
{
    if (isEmpty(q))
        return;
    
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else    
        q->front = (q->front - 1) % q->size;
}

void printQueue(queue *q)
{
    if (isEmpty(q))
        return;
    
    int temp = q->front;

    while (1)
    {
        printf("%d ", q->arr[temp]);

        if (temp == q->rear)
            break;
        
        temp = (temp+1) % q->size;
    }

    printf("\n");
}

int main() {
    queue *q;
    init(&q);

    // Enqueue at rear
    enqueueRear(q, 10);
    enqueueRear(q, 20);
    enqueueRear(q, 30);
    printQueue(q);  // Expected: 10 20 30

    // Enqueue at front
    enqueueFront(q, 5);
    enqueueFront(q, 2);
    printQueue(q);  // Expected: 2 5 10 20 30

    // Dequeue from front
    dequeueFront(q);
    printQueue(q);  // Expected: 5 10 20 30

    // Dequeue from rear
    dequeueRear(q);
    printQueue(q);  // Expected: 5 10 20

    // Fill to test circular wrap
    for (int i = 0; i < 97; i++) {
        enqueueRear(q, i + 100);
    }
    printQueue(q);  // Should show all elements in order including wrap

    // Try enqueue in full queue
    enqueueRear(q, 999);  // Should print "Queue is full!"

    return 0;
}
