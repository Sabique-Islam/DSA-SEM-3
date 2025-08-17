#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

void printList(node *ptr)
{
    printf("\n");
    while (ptr != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
    printf("\n\n");
}

node *deleteFirst(node *head)
{
    node *ptr = head;
    head = head->next;
    free(ptr);

    return head;
}

node *deleteAtIndex(node *head, int index)
{
    node *ptr1 = head;
    node *ptr2 = head->next;

    for (int i = 0; i < index - 1; i++)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    ptr1->next = ptr2->next;
    free(ptr2);

    return head;
}

node *deleteLast(node *head)
{
    node *ptr1 = head;
    node *ptr2 = head->next;

    while (ptr2->next != NULL)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    ptr1->next = NULL;
    free(ptr2);

    return head;
}

node *deleteValue(node *head, int value)
{
    node *p = head;
    node *q = head->next;

    while (q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    if (q->data == value)
    {
        p->next = q->next;
        free(q);
    }

    return head;
}

int main()
{
    system("clear");

    node *head = (node *)malloc(sizeof(node));
    node *second = (node *)malloc(sizeof(node));
    node *third = (node *)malloc(sizeof(node));
    node *fourth = (node *)malloc(sizeof(node));

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = fourth;

    fourth->data = 40;
    fourth->next = NULL;

    printList(head);

    head = deleteFirst(head);
    printList(head);

    head = deleteAtIndex(head, 2);
    printList(head);

    // head = deleteLast(head);
    // printList(head);

    head = deleteValue(head, 30);
    printList(head);

    return 0;
}
