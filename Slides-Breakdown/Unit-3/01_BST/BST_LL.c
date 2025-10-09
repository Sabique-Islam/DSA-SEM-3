#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
} node;

node *createNode(int data){
    node *temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Recursion
node *insertNode(node *root, int data){
    if (root == NULL ) return createNode(data);

    if (data < root->data) root->left = insertNode(root->left, data);
    else if (data > root->data) root->right = insertNode(root->right, data);

    return root;
}

node *insert(node *root, int data){
    if (root == NULL) return createNode(data);

    node *ptr = createNode(data);
    node *temp = root;
    node *parent = NULL;

    while (temp != NULL){
        parent = temp;
        if (data == temp->data) return root;
        else if (data < temp->data) temp = temp->left;
        else temp = temp->right;
    }

    if (ptr->data < parent->data) parent->left = ptr;
    else parent->right = ptr;

    return root;
}

node *search(node *root, int key){
    if (root == NULL) return NULL;
    else if (key == root->data) return root;
    else if (key < root->data) return search(root->left, key);
    else return search(root->right, key);
}

node *searchIterative(node *root, int key){
    if (root == NULL) return NULL;
    node *temp = root;

    while(temp != NULL){
        if (key == temp->data) return temp;
        else if (key < temp->data) temp = temp->left;
        else temp = temp->right;
    }
    return NULL;
}

int height(node  *root){
    if (root == NULL) return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return (lh > rh ? lh : rh) + 1;
}

node *InOrderPre(node *root){
    while (root && root->right) root = root->right;
    return root;
}

node *InOrderSucc(node *root){
    while (root && root->left) root = root->left;
    return root;
}

node *deleteNode(node *root, int key){
    if (root == NULL) return NULL;

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        } else if (root->left && root->right) {
            node *ptr;
            if (height(root->left) > height(root->right)) {
                ptr = InOrderPre(root->left);
                root->data = ptr->data;
                root->left = deleteNode(root->left, ptr->data);
            } else {
                ptr = InOrderSucc(root->right);
                root->data = ptr->data;
                root->right = deleteNode(root->right, ptr->data);
            }
        } else {
            node *child = (root->left) ? root->left : root->right;
            free(root);
            return child;
        }
    }
    return root;
}
