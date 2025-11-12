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

    // Add customers with different priorities
    printf("\n--- Adding Initial Customers ---\n");
    enqueue(&bank, 101, "Deposit", 2);           // Normal
    enqueue(&bank, 102, "Withdrawal", 4);        // Medium
    enqueue(&bank, 103, "Account Opening", 1);   // Normal
    enqueue(&bank, 104, "Loan Application", 7);  // High
    
    display(&bank);

    // VIP customer arrives - add with highest priority
    printf("\n--- VIP Customer Arrives ---\n");
    enqueue(&bank, 201, "Senior Citizen", 10);   // VIP
    display(&bank);

    // Serve a few customers
    printf("\n--- Serving Top Priority Customers ---\n");
    dequeue(&bank);  // Should serve VIP (201)
    dequeue(&bank);  // Should serve High (104)
    display(&bank);

    // Add more customers
    printf("\n--- More Customers Arrive ---\n");
    enqueue(&bank, 105, "Credit Card", 6);       // High
    enqueue(&bank, 106, "Statement Request", 3); // Medium
    display(&bank);

    // Another VIP arrives
    printf("\n--- Another VIP Arrives ---\n");
    enqueue(&bank, 202, "Premium Customer", 9);  // VIP
    display(&bank);

    // Test FIFO within same priority
    printf("\n--- Testing FIFO within same priority ---\n");
    enqueue(&bank, 107, "Normal Query 1", 2);    // Normal
    enqueue(&bank, 108, "Normal Query 2", 2);    // Normal (same priority)
    enqueue(&bank, 109, "Normal Query 3", 2);    // Normal (same priority)
    display(&bank);

    // Serve remaining customers
    printf("\n--- Serving All Remaining Customers ---\n");
    while (bank.front != NULL){
        dequeue(&bank);
    }

    // Try to serve from empty queue
    printf("\n--- Attempting to Serve from Empty Queue ---\n");
    dequeue(&bank);
    display(&bank);

    printf("\n========== Simulation Complete ==========\n");

    return 0;
}