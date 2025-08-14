#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *partition(struct ListNode *head, int x) {
    struct ListNode* partA = NULL;
    struct ListNode* partB = NULL;
    struct ListNode* headA = NULL;
    struct ListNode* headB = NULL;
    struct ListNode* temp = head;

    while (temp) {
        struct ListNode* newNode = malloc(sizeof(struct ListNode));
        newNode->val = temp->val;
        newNode->next = NULL;

        if (temp->val >= x) {
            if (!partA) {
                partA = newNode;
                headA = partA;
            } else {
                partA->next = newNode;
                partA = partA->next;
            }
        } else {
            if (!partB) {
                partB = newNode;
                headB = partB;
            } else {
                partB->next = newNode;
                partB = partB->next;
            }
        }
        temp = temp->next;
    }

    if (partA) partA->next = NULL;
    if (partB) partB->next = headA;

    return headB ? headB : headA;
}


// Part of Driver Code
struct ListNode *createList(int *arr, int size) {
  if (size == 0)
    return NULL;

  struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
  head->val = arr[0];
  head->next = NULL;

  struct ListNode *current = head;
  for (int i = 1; i < size; i++) {
    struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
    node->val = arr[i];
    node->next = NULL;
    current->next = node;
    current = node;
  }

  return head;
}

void printList(struct ListNode *head) {
  while (head) {
    printf("%d", head->val);
    if (head->next)
      printf(" ");
    head = head->next;
  }
  printf("\n");
}

// Driver Code:

int main() {
  int n, x;
  scanf("%d", &n);
  int arr[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  scanf("%d", &x);

  struct ListNode *head = createList(arr, n);
  struct ListNode *result = partition(head, x);
  printList(result);

  return 0;
}