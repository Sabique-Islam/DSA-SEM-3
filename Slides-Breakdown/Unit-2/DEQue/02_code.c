#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct dl *prev;
    struct dl *next;

} node;

typedef struct
{
    int size;
    node *front;
    node *rear

} deque;

node *createNode(int data)
{
    node *temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->prev = NULL;
    temp->next = NULL;

    return temp;
}

deque *createDEQueue()
{
    deque *dq = (deque*)malloc(sizeof(deque));
    dq->front = NULL;
    dq->rear = NULL;
    dq->size = 0;

    return dq;
}

void queueFront(deque *dq, int data)
{
    node *temp = createNode(data);

    if (dq->front == NULL)
    {
        dq->front = dq->rear = temp;
    }
    else
    {
        temp->next = dq->front;
        dq->front->prev = temp;
        dq->front = temp;
    }

    dq->size++;
}

void queueRear(deque *dq, int data)
{
    node *temp = createNode(data);
    
    if (dq->rear == NULL)
        dq->front = dq->rear = temp;
    else
    {
        temp->prev = dq->rear;
        dq->rear->next = temp;
        dq->rear = temp;
    }

    dq->size++;
}

int remove_front(deque* dq) {
    if (dq->head == NULL) {
        printf("Deque is empty\n");
        return -1;  // or some sentinel
    }

    node* temp = dq->head;
    int value = temp->value;

    dq->head = dq->head->next;
    if (dq->head == NULL) {        // now empty
        dq->tail = NULL;
    } else {
        dq->head->prev = NULL;
    }

    free(temp);
    dq->size--;
    return value;
}


int remove_rear(deque* dq) {
    if (dq->tail == NULL) {
        printf("Deque is empty\n");
        return -1;
    }

    node* temp = dq->tail;
    int value = temp->value;

    dq->tail = dq->tail->prev;
    if (dq->tail == NULL) {
        dq->head = NULL;
    } else {
        dq->tail->next = NULL;
    }

    free(temp);
    dq->size--;
    return value;
}

int main()
{

    return 0;
}