#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *top = NULL;

int isEmpty()
{
    if (top == NULL)
        return 1;

    return 0;
}

void push(int data)
{
    node *temp = (node *)malloc(sizeof(node));
    if (temp == NULL)
        exit(1);

    temp->data = data;
    temp->next = top;

    top = temp;
}

int pop()
{
    node *temp = top;

    if (isEmpty())
    {
        printf("\nStack Underflow...\n");
        exit(1);
    }

    top = top->next;

    int val = temp->data;

    free(temp);
    temp = NULL;

    return val;
}

int peek()
{
    if (isEmpty())
        exit(1);

    return top->data;
}

void printStack()
{
    node *temp = top;

    if (isEmpty())
    {
        printf("\nStack Underflow...\n");
        exit(1);
    }

    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int choice, data;

    while (1)
    {
        printf("\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Print the Top Element\n");
        printf("4. Print all the Elements\n");
        printf("5. Quit\n\n");

        printf("Enter your choice -> ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the Element to be pushed -> \n");
            scanf("%d", &data);
            push(data);
            break;

        case 2:
            data = pop();
            printf("Removed Element -> %d\n\n", data);
            break;

        case 3:
            printf("Top Most Element -> %d\n\n", peek());
            break;

        case 4:
            printStack();
            printf("\n");
            break;

        case 5:
            exit(1);
        }
    }

    return 0;
}
