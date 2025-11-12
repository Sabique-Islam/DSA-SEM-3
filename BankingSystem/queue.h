#ifndef QUEUE_H
#define QUEUE_H

#define MAX 100

// This is the user data
typedef struct node{
    int id;
    char type[MAX]; // array of size 100
    int priority; // can be 0 or 1
    struct node *next;
} node;

// self explanatory
typedef struct queue{
    struct node *front;
    struct node *rear;
} queue;

// Function declarations
void initQueue(queue *q);
node *create(int id, char *type, int priority);
void enqueue(queue *q, int id, char *type, int priority);
void dequeue(queue *q);
void display(queue* q);

#endif // QUEUE_H
