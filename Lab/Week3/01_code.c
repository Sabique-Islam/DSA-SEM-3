#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

// Stack implementation using array
typedef struct {
    int data[MAX];
    int top;
} Stack;

// Initialize the stack
void initStack(Stack *s) {
    s->top = -1;
}

// Check if stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Push to stack
void push(Stack *s, int value) {
    s->top += 1;
    s->data[s->top] = value;
}

// Pop from stack
int pop(Stack *s) {
    if (isEmpty(s)) printf("\nStack Underflow\n");
    
    int value = s->data[s->top];
    s->top -=  1;
    return value;
}

// Peek top of stack
int peek(Stack *s) {
    if (isEmpty(s))
        exit(1);

    return s->data[s->top];
}

// Calculate total score from operations
int calculateScore(char operations[][10], int n) {
    Stack s;
    initStack(&s);

    for (int i=0;i<n;i++) {
        if (strcmp(operations[i],"+")==0) {
            int val1=pop(&s);
            int val2=peek(&s);
            push(&s,val1);
            push(&s,val1+val2);
        } 
        else if (strcmp(operations[i],"D")==0){
            push(&s, 2 * peek(&s));
        } 
        else if (strcmp(operations[i], "C")==0){
            pop(&s);
        } 
        else {
            push(&s, atoi(operations[i]));
        }
    }

    int sum = 0;
    while (!isEmpty(&s)) {
        sum += pop(&s);
    }
    return sum;
}

// Driver code
int main() {
    int n;
    scanf("%d", &n);

    char operations[n][10];
    for (int i = 0; i < n; i++) {
        scanf("%s", operations[i]);
    }

    int result = calculateScore(operations, n);
    printf("%d\n", result);

    return 0;
}