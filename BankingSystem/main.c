/*

Create a Banking System using Queue which Simulates a banking queue system. Customers are served in FIFO order. 
Each node stores customer ID and service type. Supports enqueue, dequeue, and priority-based service.

- Add customer to queue 
- Serve next customer 
- Add priority service (complex) 
- Handle empty queue case

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// self explanatory 
void initQueue(queue *q){
    q->front = q->rear = NULL;
}

// self explanatory 
node *create(int id, char *type, int priority){
    node *temp = (node*)malloc(sizeof(node));
    temp->id = id;
    strcpy(temp->type, type);
    temp->priority = priority;
    temp->next = NULL;

    return temp;
}

// here we give the priority we want to assign the user with.
void enqueue(queue *q, int id, char *type, int priority){ 
    node *temp = create(id, type, priority);

    // when queue is empty
    if (q->front == NULL){
        q->front = q->rear = temp;
        printf("\nCustomer Enqueued with ID -> %d, TYPE -> %s, PRIORITY -> %d\n", id, type, priority);
        return;
    }

    if (priority > q->front->priority){
        temp->next = q->front;
        q->front = temp;
        printf("\nCustomer Enqueued with ID -> %d, TYPE -> %s, PRIORITY -> %d\n", id, type, priority);
        return;
    }

    node *new = q->front;
    while(new->next != NULL && new->next->priority >= priority){
        new = new->next;
    }

    temp->next = new->next;
    new->next = temp;

    if (temp->next == NULL) q->rear = temp;
    printf("\nCustomer Enqueued with ID -> %d, TYPE -> %s, PRIORITY -> %d\n", id, type, priority);
}

void dequeue(queue *q){
    if (q->front == NULL){
        printf("No Customers....\n");
        return;
    }

    node *temp = q->front;
    printf("Serving Customer %d (%s, priority %d)\n", temp->id, temp->type, temp->priority);

    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
}

void display(queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    node* temp = q->front;
    printf("\nCurrent Queue:\n");
    while (temp != NULL) {
        printf("[ID: %d, Service: %s, Priority: %d] -> ",temp->id, temp->type, temp->priority);
        temp = temp->next;
    }
    printf("NULL\n");
}


// AI Generated Test Case
int main() {
    queue bank;
    initQueue(&bank);

    printf("\n=== BANK QUEUE SIMULATION ===\n");

    // Add normal customers
    enqueue(&bank, 101, "Deposit", 0);
    enqueue(&bank, 102, "Withdrawal", 0);

    // Add priority customer (should go to front)
    enqueue(&bank, 201, "Loan", 1);

    // Add another normal
    enqueue(&bank, 103, "AccountOpen", 0);

    display(&bank);

    printf("\n--- Serving Customers ---\n");
    dequeue(&bank);  // should serve priority (201)
    dequeue(&bank);  // then normal (101)
    display(&bank);

    // Add new priority again
    enqueue(&bank, 202, "CreditCard", 1);
    enqueue(&bank, 203, "KYC", 0);

    display(&bank);

    // Dequeue all
    printf("\n--- Serving All ---\n");
    while (bank.front != NULL)
        dequeue(&bank);

    // Handle empty case
    dequeue(&bank);

    display(&bank);

    return 0;
}