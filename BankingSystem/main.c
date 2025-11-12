/*

Create a Banking System using Queue which Simulates a banking queue system. Customers are served in FIFO order. 
Each node stores customer ID and service type. Supports enqueue, dequeue, and priority-based service.

- Add customer to queue 
- Serve next customer 
- Add priority service (complex) 
- Handle empty queue case

*/

#include <stdio.h>
#include "queue.h"

// AI Generated Test Case
int main() {
    queue bank;
    initQueue(&bank);

    printf("\n=== BANK QUEUE SIMULATION ===\n");

    // Add normal customers
    enqueue(&bank, 101, "Deposit", 0);
    enqueue(&bank, 102, "Withdrawal", 0);

    // Add priority customer (should go to front)
    enqueue(&bank, 201, "Loan", 1);

    // Add another normal
    enqueue(&bank, 103, "AccountOpen", 0);

    display(&bank);

    printf("\n--- Serving Customers ---\n");
    dequeue(&bank);  // should serve priority (201)
    dequeue(&bank);  // then normal (101)
    display(&bank);

    // Add new priority again
    enqueue(&bank, 202, "CreditCard", 1);
    enqueue(&bank, 203, "KYC", 0);

    display(&bank);

    // Dequeue all
    printf("\n--- Serving All ---\n");
    while (bank.front != NULL)
        dequeue(&bank);

    // Handle empty case
    dequeue(&bank);

    display(&bank);

    return 0;
}