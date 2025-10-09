#include <stdlib.h>
#include <stdio.h>

typedef struct node{
    int data;
    struct node *right;
    struct node *left;
} node;

typedef struct {
    node **arr;
    int top;
    int size;
} stack;

stack *createStack(int size){
    stack *gang = (stack*)malloc(sizeof(stack));
    gang->arr = (node**)malloc(sizeof(node*) * size);
    gang->top = -1;
    gang->size = size;

    return gang;
}

node *createNode(int data){
    node *head = (node*)malloc(sizeof(node));
    head->data = data;
    head->right = head->left = NULL;
    return head;
}

int isEmpty(stack *gang){
    if (gang->arr == -1) return 1;
    return 0;
}

node *pop(stack *gang){
    if (isEmpty(gang)) return NULL;
    return gang->arr[gang->top--];
}

node *peek(stack *gang){
    if (isEmpty(gang)) return NULL;
    return gang->arr[gang->top];
}

void push(stack *gang, node *head){
    if (gang->top < gang->size - 1) gang->arr[gang->top++] = head;
}

void inorder(node *root){
    stack *gang = createStack(100);
    node *temp = root;
    while (temp!=NULL && !isEmpty(gang)){
        while (temp!=NULL){
            push(gang, temp);
            temp = temp->left;
        }
        temp = pop(gang);
        printf("%d ", temp->data);
        temp = temp->right;
    }
    free(gang);
}

void preorder(node *root){
    stack *gang = createStack(100);
    push(gang, root);

    while (!isEmpty(gang)) {
        node *temp = pop(gang);
        printf("%d ", temp->data);

        if (temp->right) push(gang, temp->right);
        if (temp->left)  push(gang, temp->left);
    }
    free(gang);
}

void postorder(node *root) {

    stack *stack1 = createStack(100);
    stack *stack2 = createStack(100);

    push(stack1, root);
    while (!isEmpty(stack1)) {
        node *temp = pop(stack1);
        push(stack2, temp);

        if (temp->left)  push(stack1, temp->left);
        if (temp->right) push(stack1, temp->right);
    }

    while (!isEmpty(stack2)) {
        printf("%d ", pop(stack2)->data);
    }
    free(stack1);
    free(stack2);
}
