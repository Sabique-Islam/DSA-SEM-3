#ifndef QUEUE_H
#define QUEUE_H

#define MAX 100
#define MIN_PRIORITY 0
#define MAX_PRIORITY 10

/*

Priority Levels:
- 0-2: Normal customers (Regular, Account Opening)
- 3-5: Medium priority (Deposits, Withdrawals)
- 6-8: High priority (Loans, Credit Cards)
- 9-10: VIP/Emergency (Senior Citizens, Urgent Transactions)

*/

// This is the user data
typedef struct node{
    int id;
    char type[MAX]; // array of size 100
    int priority; // Range: 0-10 (0=lowest, 10=highest)
    struct node *next;
} node;

// self explanatory
typedef struct queue{
    struct node *front;
    struct node *rear;
} queue;

// Function declarations
void initQueue(queue *q);
node *create(int id, char *type, int priority);
void enqueue(queue *q, int id, char *type, int priority);
void dequeue(queue *q);
void display(queue* q);

#endif // QUEUE_H
