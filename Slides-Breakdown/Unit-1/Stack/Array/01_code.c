#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 4

int stackArr[MAX];
int top = -1;

bool isFull()
{
    if (top == MAX - 1)
        return true;
    return false;
}

bool isEmpty()
{
    if (top == -1)
        return true;
    return false;
}

void push(int data)
{
    if (isFull())
    {
        printf("\nStack Overflow\n");
        return;
    }
    top += 1;
    stackArr[top] = data;
}

int pop()
{
    int value;

    if (isEmpty())
    {
        printf("\nStack Underflow\n");
        exit(1); // abnormal termination of the program
    }

    value = stackArr[top];
    top -= 1;
    return value;
}

int topMost()
{
    if (isEmpty())
    {
        printf("\nStack Underflow\n");
        exit(1); // abnormal termination of the program
    }

    return stackArr[top];
}

void printStack()
{
    if (isEmpty())
    {
        printf("\nStack Underflow\n");
        return;
    }
    for (int i = top; i >= 0; i--)
    {
        printf("%d ", stackArr[i]);
    }
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
            printf("Top Most Element -> %d\n\n", topMost());
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