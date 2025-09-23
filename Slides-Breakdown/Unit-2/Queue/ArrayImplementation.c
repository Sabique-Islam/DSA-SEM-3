#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
    int size;
    int front;
    int rear;
    int *arr;
} queue;

int isFull(queue *q)
{
    if (q->rear == q->size-1) return 1;
    return 0;
}

int isEmpty(queue *q)
{
    if (q->rear == q->front) return 1;
    return 0;
}

void enqueue(queue *q, int data)
{
    if (isFull(q)) return;

    q->rear++;
    q->arr[q->rear] = data;
}

int dequeue(queue *q)
{
    if (isEmpty(q)) exit(1);

    q->front++;
    return q->arr[q->front];
}

void printQueue(queue *q)
{
    if (isEmpty(q)){
        printf("\nQueue is Empty...\n");
        return;
    }
        

    for(int i = q->front+1; i < q->rear+1; i++)
    {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int main() 
{
    queue q;
    q.size = 100;
    q.front = q.rear = -1;

    q.arr = (int*)malloc(q.size*sizeof(int));

     // Enqueue some test data
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    printQueue(&q);

    // Dequeue two elements
    printf("Dequeued: %d\n", dequeue(&q));
    printf("Dequeued: %d\n", dequeue(&q));

    printQueue(&q);

    // Add more elements
    enqueue(&q, 60);
    enqueue(&q, 70);

    printQueue(&q);

    // Dequeue everything
    while (!isEmpty(&q))
    {
        printf("Dequeued: %d\n", dequeue(&q));
    }

    printQueue(&q);

    free(q.arr);

    return 0;
}