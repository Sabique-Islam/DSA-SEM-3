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

// Priority Queue Enqueue: Higher priority goes first, same priority follows FIFO
void enqueue(queue *q, int id, char *type, int priority){ 
    // Clamp priority within valid range 0-10
    if (priority < MIN_PRIORITY) priority = MIN_PRIORITY;
    if (priority > MAX_PRIORITY) priority = MAX_PRIORITY;
    
    node *temp = create(id, type, priority);

    // When queue is empty
    if (q->front == NULL){
        q->front = q->rear = temp;
        printf("\nCustomer Enqueued -> ID: %d, Service: %s, Priority: %d\n", id, type, priority);
        return;
    }

    // If new customer has higher priority than front, insert at front
    if (priority > q->front->priority){
        temp->next = q->front;
        q->front = temp;
        printf("\nCustomer Enqueued -> ID: %d, Service: %s, Priority: %d (High Priority - moved to front)\n", id, type, priority);
        return;
    }

    // Find position: skip all nodes with strictly higher priority
    // Then skip all nodes with same priority (FIFO within same priority)
    node *current = q->front;
    while(current->next != NULL && current->next->priority >= priority){
        current = current->next;
    }

    // Insert after current node
    temp->next = current->next;
    current->next = temp;

    // Update rear if inserted at end
    if (temp->next == NULL) q->rear = temp;
    
    printf("\nCustomer Enqueued -> ID: %d, Service: %s, Priority: %d\n", id, type, priority);
}

void dequeue(queue *q){
    if (q->front == NULL){
        printf("\nNo Customers in queue....\n");
        return;
    }

    node *temp = q->front;
    printf("\n>>> Serving Customer ID: %d | Service: %s | Priority: %d\n",temp->id, temp->type, temp->priority);

    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
}

void display(queue* q) {
    if (q->front == NULL) {
        printf("\nQueue is empty.\n");
        return;
    }

    node* temp = q->front;
    int position = 1;
    printf("  Position | Customer ID | Service Type        | Priority\n\n");
    
    while (temp != NULL) {
        const char *level;
        if (temp->priority >= 9) level = "VIP";
        else if (temp->priority >= 6) level = "HIGH";
        else if (temp->priority >= 3) level = "MED";
        else level = "NORM";
        
        printf("  %-8d | %-11d | %-19s | %d (%s)\n", 
               position++, temp->id, temp->type, temp->priority, level);
        temp = temp->next;
    }
    printf("  Total customers in queue: %d\n", position - 1);
    printf("  Next to be served: Customer ID %d (Priority %d)\n", q->front->id, q->front->priority);
}


int queueLength(queue *q){
    int count = 0;
    node *temp = q->front;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}