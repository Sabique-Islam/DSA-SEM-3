#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 1000


// TODO 1 === TreeNode definition ===
typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// === Queue for level-order construction ===
typedef struct {
  TreeNode* data[MAX_NODES];
  int front;
  int rear;
} Queue;

void enqueue(Queue* q, TreeNode* node) {
  q->data[q->rear++] = node;
}

TreeNode* dequeue(Queue* q) {
  return q->data[q->front++];
}

int isEmpty(Queue* q) {
  return q->front == q->rear;
}

// TODO 2 === Create a new TreeNode ===
TreeNode* createNode(int val) {
    TreeNode *root = (TreeNode*)malloc(sizeof(TreeNode));
    if (!root) return NULL;
    root->data = val;
    root->left = root->right = NULL;
    
    return root;
}

//TODO 3  === Inorder traversal to find k-th smallest ===
void inorder(TreeNode* root, int* k, int* result) {
    if (!root) return;
    inorder(root->left, k, result);
    if (*k==0) return;
    (*k)--;
    if (*k==0){
        *result = root->data;
        return;
    }
    inorder(root->right, k, result);
}

//TODO 4 == find kth == calls inorder func
int kthSmallest(TreeNode* root, int k) {
    int result = -1;
    inorder(root, &k, &result);
    return result;
}

// === Build Tree from Level-Order Input (space-separated, handles "null") ===
TreeNode* buildTreeFromLevelOrder(char* input) {
  if (strlen(input) == 0) return NULL;

  char* tokens[MAX_NODES];
  int count = 0;

  char* token = strtok(input, " ");
  while (token) {
  tokens[count++] = token;
  token = strtok(NULL, " ");
  }

  if (count == 0 || strcmp(tokens[0], "null") == 0) return NULL;

  TreeNode* root = createNode(atoi(tokens[0]));
  Queue q = { .front = 0, .rear = 0 };
  enqueue(&q, root);

  int i = 1;
  while (!isEmpty(&q) && i < count) {
  TreeNode* current = dequeue(&q);

  // Left child
  if (i < count && strcmp(tokens[i], "null") != 0) {
  current->left = createNode(atoi(tokens[i]));
  enqueue(&q, current->left);
  }
  i++;

  // Right child
  if (i < count && strcmp(tokens[i], "null") != 0) {
  current->right = createNode(atoi(tokens[i]));
  enqueue(&q, current->right);
  }
  i++;
  }

  return root;
}

void freeTree(TreeNode* root) {
  if (!root) return;
  freeTree(root->left);
  freeTree(root->right);
  free(root);
}

// === Main function (single input) ===
int main() {
  char input[1000];
  int k;

  // Read BST (level-order as a single line)
  fgets(input, sizeof(input), stdin);
  input[strcspn(input, "\n")] = '\0';

  // Read k
  scanf("%d", &k);

  TreeNode* root = buildTreeFromLevelOrder(input);
  int result = kthSmallest(root, k);

  printf("%d\n", result);

  freeTree(root);
  return 0;
}