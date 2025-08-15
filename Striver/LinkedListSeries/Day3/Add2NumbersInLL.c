#include <stdio.h>

typedef struct ListNode
{
    int val;
    struct ListNode *next;
} node;

node *newNode(int data)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->val = data;
    temp->next = NULL;
    return temp;
}

node *addTwoNumbers(node *l1, node *l2)
{
    node *temp1 = l1;
    node *temp2 = l2;

    node *dummyNode = newNode(-1);
    node *current = dummyNode;

    int carry = 0;

    while (temp1 || temp2)
    {
        int sum = carry;

        if (temp1)
            sum += temp1->val;
        if (temp2)
            sum += temp2->val;

        node *newnode = newNode(sum % 10);
        carry = sum / 10;

        current->next = newnode;
        current = current->next;

        if (temp1)
            temp1 = temp1->next;
        if (temp2)
            temp2 = temp2->next;
    }

    if (carry)
    {
        node *newnode = newNode(carry);
        current->next = newnode;
    }

    return dummyNode->next;
}
