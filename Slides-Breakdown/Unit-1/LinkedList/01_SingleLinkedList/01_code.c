#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

void printList(node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

node *insertAtFirst(node *new, int data)
{
    node *ptr = (node *)malloc(sizeof(node));
    ptr->next = new;
    ptr->data = data;
    return ptr;
}

node *insertAtLast(node *head, int data)
{
    node *temp = (node *)malloc(sizeof(node));
    /*
    A head pointer is essential for the entire list. 
    Using a temporary pointer to traverse, prevents us from losing access to the beginning of the list.
    */
    node *ptr = head;

    temp->data = data;
    temp->next = NULL;

    if (head == NULL)
    {
        // If list is empty, return new node as the head!
        return temp; // New head = new node, ezzz
    }

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    ptr->next = temp;
    return head;
}

int checkIfPresent(node *head, int val)
{
    node *temp = (node *)malloc(sizeof(node));
    temp = head;
    while (temp != NULL)
    {
        if (temp->data == val)
        {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int main()
{
    node *first = (node *)malloc(sizeof(node));
    node *second = (node *)malloc(sizeof(node));

    first->data = 7;
    first->next = second;
    second->data = 8;
    second->next = NULL;

    printList(first);
    first = insertAtFirst(first, 9);
    printList(first);
    insertAtLast(second, 10);
    printList(first);

    int result = checkIfPresent(first, 10);
    if (result)
        printf("Present");

    return 0;
}