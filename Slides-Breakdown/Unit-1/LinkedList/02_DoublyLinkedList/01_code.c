#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
} node;

void PrintDoublyLinkedList(node *head)
{
    while (head)
    {
        printf("%d <- -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

node *AddToEmpty(node *head, int data)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    head = temp;
    return head;
}

node *InsertAtStart(node *head, int data)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->prev = NULL;
    temp->data = data;

    if (head != NULL)
    {
        // If the list is not empty, link the new node to the old head.
        temp->next = head;
        head->prev = temp;
    }
    else
    {
        temp->next = NULL; // If the list is empty, the new node's next pointer should be NULL.
    }

    head = temp;
    return head;
}

node *InsertAtEnd(node *head, int data)
{
    node *temp = (node *)malloc(sizeof(node));

    if (temp == NULL)
        return head;

    // Initialize pointers to NULL for safety, especially in edge cases like an empty list where the node has no prev or next.
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;

    if (head == NULL)
        return temp;

    node *ptr = head;

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    ptr->next = temp;
    temp->prev = ptr;

    return head;
}

void insertAfter(node *head, int x, int y)
{
    node *current = head;

    while (current && current->data != y)
        current = current->next;

    if (!current)
    {
        printf("\nData Not Found\n");
        return;
    }

    node *newNode = (node *)malloc(sizeof(node));
    if (!newNode)
    {
        printf("\nMemory Allocation failed...\n");
        return;
    }

    newNode->data = x;
    newNode->next = current->next;
    newNode->prev = current;

    if (current->next)
        current->next->prev = newNode;

    current->next = newNode;
}

node *ReverseDoublyLinkedList(node *head)
{
    node *temp = NULL;
    node *current = head;

    // Traverse the list
    while (current != NULL)
    {
        // Swap prev and next pointers for the current node
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        // Move to the next node in the original list
        current = current->prev;
    }
    // Before the final step, check for an empty list
    if (temp != NULL)
    {
        // The new head will be the last node of the original list
        head = temp->prev;
    }
    return head;
}

int main()
{
    node *head = NULL;

    head = AddToEmpty(head, 10);
    PrintDoublyLinkedList(head);

    head = InsertAtStart(head, 20);
    PrintDoublyLinkedList(head);

    head = InsertAtEnd(head, 30);
    PrintDoublyLinkedList(head);

    head = ReverseDoublyLinkedList(head);
    PrintDoublyLinkedList(head);

    insertAfter(head, 50, 10);
    PrintDoublyLinkedList(head);

    return 0;
}