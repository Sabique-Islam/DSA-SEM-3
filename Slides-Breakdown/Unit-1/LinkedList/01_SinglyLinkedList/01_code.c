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

node *insertAtIndex(node *head, int data, int index)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = data;

    if (index == 0)
    {
        head = insertAtFirst(head, data);
        return head;
    }

    node *ptr = head;

    int i = 0;

    while (i != index - 1)
    {
        ptr = ptr->next;
        i++;
    }

    temp->next = ptr->next;
    ptr->next = temp;

    return head;
}

node *insertAfterNode(node *head, node *prevNode, int data)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = data;

    node *ptr = head;

    temp->next = prevNode->next;
    prevNode->next = temp;

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
    node *head = (node *)malloc(sizeof(node));
    node *second = (node *)malloc(sizeof(node));

    head->data = 7;
    head->next = second;
    second->data = 8;
    second->next = NULL;

    printList(head);
    head = insertAtFirst(head, 9);
    printList(head);
    head = insertAtLast(head, 10);
    printList(head);

    int result = checkIfPresent(head, 10);
    if (result)
        printf("Present\n");

    head = insertAtIndex(head, 20, 2);
    printList(head);

    head = insertAtIndex(head, 15, 0);
    printList(head);

    head = insertAfterNode(head, second, 70);
    printList(head);

    return 0;
}
