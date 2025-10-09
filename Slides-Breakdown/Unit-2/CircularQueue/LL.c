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

int kthDequeue(int k)
{
    int val = -1;
    node *current = front;
    node *prev = front;

    current = current->next;

    if (front == NULL)
        return -1;
    
    for (int i = 0; i < k - 1; i++)
    {
        current = current->next;
        prev = prev->next;
    }

    val = current->data;

    prev->next = current->next;

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
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    display();

    printf("Remove Kth index -> %d\n", kthDequeue(4));

    display();

    return 0;
}