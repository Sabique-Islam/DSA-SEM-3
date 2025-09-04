#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10000

// Define a structure for a Queue
typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
    int size;
} Queue;

// Function to initialize a queue
void initQueue(Queue* q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

// Function to check if the queue is empty
int isEmpty(Queue* q) {
    return q->size == 0;
}

// Function to check if the queue is full
int isFull(Queue* q) {
    return q->size == MAX_SIZE;
}

// Function to add an element to the rear of the queue
void enqueue(Queue* q, int value) {
    if (isFull(q))
    {
        return;
    }
    q->rear = (q->rear+1) % MAX_SIZE;
    q->data[q->rear] = value;
    q->size++;
}

// Function to remove and return the element from the front of the queue
int dequeue(Queue* q) {
    if (isEmpty(q))
    {
        return -1;
    }
    int val = q->data[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
    q->size--;
    return val;
}

// Function to get the front element without removing it
int peek(Queue* q) {
    if (isEmpty(q))
    {
        return -1;
    }
    
    return q->data[q->front];
}

// Main function to solve the problem using the Queue data structure
int timeRequiredToBuy(int* tickets, int ticketsSize, int k) {
    int time = 0;
    
    for (int i = 0; i < ticketsSize; i++)
    {
        if (i <= k)
        {
            time += (tickets[i] < tickets[k]) ? tickets[i] : tickets[k];
        }else{
            time += (tickets[i] < tickets[k] - 1) ? tickets[i] : (tickets[k] - 1);
        }
    }
    return time;
}

// Driver code to test the solution
int main() {
    int n, k;
    scanf("%d", &n);
    int* tickets = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) {
        scanf("%d", &tickets[i]);
    }
    scanf("%d", &k);
    int result = timeRequiredToBuy(tickets, n, k);
    printf("%d", result);
    free(tickets);
    return 0;
}