#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *getIntersectionNode(struct ListNode *headA,
                                     struct ListNode *headB) {
    struct ListNode* tempA = headA;
    struct ListNode* tempB = headB;
    
    while(tempA!=tempB){
        tempA = (tempA!=NULL)?tempA->next:headA;
        tempB = (tempB!=NULL)?tempB->next:headB;
    }
    return tempA;
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
    current->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    current = current->next;
    current->val = arr[i];
    current->next = NULL;
  }
  return head;
}

struct ListNode *getNodeAt(struct ListNode *head, int index) {
  while (index-- > 0 && head) {
    head = head->next;
  }
  return head;
}


// Driver Code:

int main() {
  int n, m;
  scanf("%d", &n);
  int arrA[n];
  for (int i = 0; i < n; i++)
    scanf("%d", &arrA[i]);

  scanf("%d", &m);
  int arrB[m];
  for (int i = 0; i < m; i++)
    scanf("%d", &arrB[i]);

  int skipA, skipB;
  scanf("%d", &skipA);
  scanf("%d", &skipB);

  struct ListNode *headA = createList(arrA, n);

  struct ListNode *headB = NULL;
  if (skipB == 0) {
    headB = getNodeAt(headA, skipA);
  } else {
    headB = createList(arrB, skipB);
    struct ListNode *tailB = headB;
    while (tailB && tailB->next)
      tailB = tailB->next;
    if (tailB)
      tailB->next = getNodeAt(headA, skipA);
  }

  struct ListNode *result = getIntersectionNode(headA, headB);
  if (result)
    printf("%d\n", result->val);
  else
    printf("-1\n");

  return 0;
}