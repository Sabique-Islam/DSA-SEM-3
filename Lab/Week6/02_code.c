#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h> // For INT_MIN

#define MAX_NODES 1000

// TODO 1: === Define TreeNode struct ===
typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Queue for TreeNode pointers
typedef struct {
  TreeNode* data[MAX_NODES];
  int front;
  int rear;
} Queue;

void enqueue(Queue* q, TreeNode* node) {
  if (q->rear >= MAX_NODES) {
  fprintf(stderr, "Queue overflow.\n");
  return;
  }
  q->data[q->rear++] = node;
}

TreeNode* dequeue(Queue* q) {
  if (q->front == q->rear) {
  return NULL;
  }
  return q->data[q->front++];
}

int isEmpty(Queue* q) {
  return q->front == q->rear;
}


// === TODO 2: Create a new TreeNode ===
// Hint: Use malloc, assign val, and set left/right to NULL
TreeNode* createNode(int val) {
    TreeNode *root = (TreeNode*)malloc(sizeof(TreeNode));
    if (!root) return NULL;
    root->data = val;
    root->left = root->right = NULL;
    
    return root;
}


// === TODO 3: Main function to count good nodes ===
// === Create new Helper function for goodNodes (DFS traversal) ===

int countGoodNodes(TreeNode* node, int max) {
    if (!node) return 0;

    int count = 0;
    if (node->data >= max) count = 1;

    int newMax = (node->data > max) ? node->data : max;

    count += countGoodNodes(node->left, newMax);
    count += countGoodNodes(node->right, newMax);

    return count;
}

int goodNodes(TreeNode* root) {
    return countGoodNodes(root, INT_MIN);
}



// Builds tree from space-separated level-order input
TreeNode* buildTreeFromLevelOrder(char* input) {
  if (!input || strlen(input) == 0) return NULL;

  char* tokens[MAX_NODES];
  int count = 0;

  char* token = strtok(input, " ");
  while (token && count < MAX_NODES) {
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

  if (i < count && strcmp(tokens[i], "null") != 0) {
  current->left = createNode(atoi(tokens[i]));
  enqueue(&q, current->left);
  }
  i++;

  if (i < count && strcmp(tokens[i], "null") != 0) {
  current->right = createNode(atoi(tokens[i]));
  enqueue(&q, current->right);
  }
  i++;
  }

  return root;
}

// Frees tree memory recursively
void freeTree(TreeNode* root) {
  if (!root) return;
  freeTree(root->left);
  freeTree(root->right);
  free(root);
}

// Main function
int main() {
  char input[1000];

  // Read tree in level-order (space-separated)
  fgets(input, sizeof(input), stdin);
  input[strcspn(input, "\n")] = '\0'; // Remove newline

  TreeNode* root = buildTreeFromLevelOrder(input);

  int good_nodes_count = goodNodes(root);
  printf("%d\n", good_nodes_count);

  freeTree(root);
  return 0;
}