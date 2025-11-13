/*

Create a Banking System using Queue which Simulates a banking queue system. Customers are served in FIFO order. 
Each node stores customer ID and service type. Supports enqueue, dequeue, and priority-based service.

- Add customer to queue 
- Serve next customer 
- Add priority service (complex) 
- Handle empty queue case

*/

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void displayMenu() {
    printf("  1. Add Customer to Queue\n");
    printf("  2. Serve Next Customer\n");
    printf("  3. Display Current Queue\n");
    printf("  4. View Priority Information\n");
    printf("  5. Exit\n");
    printf("Enter your choice: ");
}

void displayPriorityInfo() {
    printf("  Priority Range: 0-10 (0=Lowest, 10=Highest)\n");
    printf("  ───────────────────────────────────────────────\n");
    printf("  0-2  : Normal Priority\n");
    printf("         (Regular queries, Account opening)\n");
    printf("  3-5  : Medium Priority\n");
    printf("         (Deposits, Withdrawals, Statements)\n");
    printf("  6-8  : High Priority\n");
    printf("         (Loans, Credit Cards, Urgent requests)\n");
    printf("  9-10 : VIP/Emergency\n");
    printf("         (Senior Citizens, Premium customers)\n");
}

int main() {
    queue bank;
    initQueue(&bank);
    
    int choice;
    int customerId;
    char serviceType[MAX];
    int priority;
    
    while(1) {
        displayMenu();
        
        if(scanf("%d", &choice) != 1) {
            // Clear invalid input
            while(getchar() != '\n');
            printf("\nInvalid input! Please enter a number.\n");
            continue;
        }
        // Clear input buffer
        while(getchar() != '\n');
        
        switch(choice) {
            case 1:
                printf("\n─── Add Customer to Queue ───\n");
                printf("Enter Customer ID: ");
                if(scanf("%d", &customerId) != 1) {
                    while(getchar() != '\n');
                    printf("Invalid ID! Operation cancelled.\n");
                    break;
                }
                while(getchar() != '\n');
                
                printf("Enter Service Type: ");
                if(fgets(serviceType, MAX, stdin) != NULL) {
                    // Remove newline character if present
                    size_t len = 0;
                    while(serviceType[len] != '\0' && serviceType[len] != '\n') len++;
                    if(serviceType[len] == '\n') serviceType[len] = '\0';
                }
                
                printf("Enter Priority (0-10): ");
                if(scanf("%d", &priority) != 1) {
                    while(getchar() != '\n');
                    printf("Invalid priority! Operation cancelled.\n");
                    break;
                }
                while(getchar() != '\n');
                
                enqueue(&bank, customerId, serviceType, priority);
                break;
                
            case 2:
                printf("\n─── Serve Next Customer ───\n");
                dequeue(&bank);
                break;
                
            case 3:
                display(&bank);
                break;
                
            case 4:
                displayPriorityInfo();
                break;
                
            case 5:
                printf("Thank you for using Bank Queue System!\n");
                
                // Clean up remaining customers
                while(bank.front != NULL) {
                    node *temp = bank.front;
                    bank.front = bank.front->next;
                    free(temp);
                }
                return 0;
                
            default:
                printf("\nInvalid choice! Please select 1-5.\n");
        }
    }
    
    return 0;
}