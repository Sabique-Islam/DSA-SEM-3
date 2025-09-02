#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *front = NULL;
node *rear = NULL;

void enqueue(int data)
{
    node *newEntry = (node *)malloc(sizeof(node));
    newEntry->data = data;
    newEntry->next = NULL;

    if (front == NULL) // means empty queue
    {
        front = rear = newEntry;
        rear->next = front; // since circular
    }
    else // rear->next = front in this case cuz queue aint empty :)
    {
        rear->next = newEntry; // new rear next
        rear = newEntry;
        rear->next = front;
    }
}

int dequeue()
{
    int val = -1;

    if (front == NULL)
        exit(1);

    if (front == rear) // only 1 node
    {
        val = front->data;
        free(front);
        front = rear = NULL;
    }
    else
    {
        node *temp = front;
        val = temp->data;

        front = front->next;
        rear->next = front;

        free(temp);
    }

    return val;
}

void display()
{
    if (front == NULL)
        return;
    
    node *temp = front;

    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);

    printf("\n");
}

int main()
{
    printf("Enqueue 10, 20, 30\n");
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();  // should print: 10 20 30

    printf("Dequeue -> %d\n", dequeue()); // removes 10
    display();  // should print: 20 30

    printf("Enqueue 40\n");
    enqueue(40);
    display();  // should print: 20 30 40

    printf("Dequeue -> %d\n", dequeue()); // removes 20
    printf("Dequeue -> %d\n", dequeue()); // removes 30
    display();  // should print: 40

    printf("Dequeue -> %d\n", dequeue()); // removes 40, now empty
    display();  // should print: Queue is empty

    printf("Terminate Dequeue -> %d\n", dequeue()); // should terminate program

    return 0;
}