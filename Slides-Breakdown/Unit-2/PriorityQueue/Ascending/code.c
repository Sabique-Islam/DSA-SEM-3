#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int data;
    int priority;
} Element;

typedef struct {
    Element arr[MAX];
    int size;
} PriorityQueue;

// Initialize the queue
void initQueue(PriorityQueue *pq) { // lmao — gpt gen (not really :)
    pq->size = 0;
}

// Enqueue element in ascending priority order
void enqueue(PriorityQueue *pq, int data, int priority) {
    if (pq->size == MAX) {
        printf("Queue Overflow!\n");
        return;
    }
    int i = pq->size - 1;
    // Shift elements to maintain ascending priority
    while (i >= 0 && pq->arr[i].priority > priority) {
        pq->arr[i + 1] = pq->arr[i];
        i--;
    }
    pq->arr[i + 1].data = data;
    pq->arr[i + 1].priority = priority;
    pq->size++;
}

// Dequeue element (remove element with smallest priority)
Element dequeue(PriorityQueue *pq) {
    Element e = {-1, -1};
    if (pq->size == 0) {
        printf("Queue Underflow!\n");
        return e;
    }
    e = pq->arr[0];
    // Shift all elements left
    for (int i = 1; i < pq->size; i++) {
        pq->arr[i - 1] = pq->arr[i];
    }
    pq->size--;
    return e;
}

// Display the queue
void display(PriorityQueue *pq) {
    if (pq->size == 0) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Data(Priority): ");
    for (int i = 0; i < pq->size; i++) {
        printf("%d(%d) ", pq->arr[i].data, pq->arr[i].priority);
    }
    printf("\n");
}

int main() {
    PriorityQueue pq;
    initQueue(&pq);

    enqueue(&pq, 10, 3);
    enqueue(&pq, 20, 1);
    enqueue(&pq, 30, 2);

    display(&pq);

    Element e = dequeue(&pq);
    printf("Dequeued: %d(%d)\n", e.data, e.priority);

    display(&pq);

    return 0;
}
