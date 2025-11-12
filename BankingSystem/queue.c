#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

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
