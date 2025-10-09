// Circular SLL

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *addToEmpty(node *head, int data)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->next = temp;

    head = temp;
    return head;
}

void CircularTraversal(node *head)
{
    node *temp = head;
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("\n");
}

node *insertAtFirst(node *head, int data)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = data;

    node *ptr = head;

    while (ptr->next != head)
    {
        ptr = ptr->next;
    }

    ptr->next = temp;
    temp->next = head;

    head = temp;

    return head;
}

node *insertAtLast(node *head, int data)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;

    node* ptr = head;

    while(ptr->next!=head)
    {
        ptr = ptr->next;
    }

    ptr->next = temp;
    temp->next = head;

    return head;
}

node *insertAtPosition(node *head, int data, int position)
{
    node* temp = (node*)malloc(sizeof(node));

    return head;
}

int main()
{
    system("clear");
    printf("\nCircular Singly Linked List --> \n\n");

    node *head = NULL;

    head = addToEmpty(head, 1);
    CircularTraversal(head);

    head = insertAtFirst(head, 12);
    CircularTraversal(head);

    head = insertAtFirst(head, 123);
    CircularTraversal(head);

    head = insertAtLast(head, 1234);
    CircularTraversal(head);

    // printf("\nSize of Node -> %lu", sizeof(node)); // 16 bytes
    printf("\n");
    return 0;
}
