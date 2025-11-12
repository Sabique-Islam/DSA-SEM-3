# Test Case Ouput ->

```

=== BANK QUEUE SIMULATION ===

--- Adding Initial Customers ---

Customer Enqueued -> ID: 101, Service: Deposit, Priority: 2

Customer Enqueued -> ID: 102, Service: Withdrawal, Priority: 4 (High Priority - moved to front)

Customer Enqueued -> ID: 103, Service: Account Opening, Priority: 1

Customer Enqueued -> ID: 104, Service: Loan Application, Priority: 7 (High Priority - moved to front)

--- Current Queue ---
[ID: 104, Service: Loan Application, Priority: 7] -> [ID: 102, Service: Withdrawal, Priority: 4] -> [ID: 101, Service: Deposit, Priority: 2] -> [ID: 103, Service: Account Opening, Priority: 1] -> NULL

--- VIP Customer Arrives ---

Customer Enqueued -> ID: 201, Service: Senior Citizen, Priority: 10 (High Priority - moved to front)

--- Current Queue ---
[ID: 201, Service: Senior Citizen, Priority: 10] -> [ID: 104, Service: Loan Application, Priority: 7] -> [ID: 102, Service: Withdrawal, Priority: 4] -> [ID: 101, Service: Deposit, Priority: 2] -> [ID: 103, Service: Account Opening, Priority: 1] -> NULL

--- Serving Top Priority Customers ---

>>> Serving Customer ID: 201 | Service: Senior Citizen | Priority: 10

>>> Serving Customer ID: 104 | Service: Loan Application | Priority: 7

--- Current Queue ---
[ID: 102, Service: Withdrawal, Priority: 4] -> [ID: 101, Service: Deposit, Priority: 2] -> [ID: 103, Service: Account Opening, Priority: 1] -> NULL

--- More Customers Arrive ---

Customer Enqueued -> ID: 105, Service: Credit Card, Priority: 6 (High Priority - moved to front)

Customer Enqueued -> ID: 106, Service: Statement Request, Priority: 3

--- Current Queue ---
[ID: 105, Service: Credit Card, Priority: 6] -> [ID: 102, Service: Withdrawal, Priority: 4] -> [ID: 106, Service: Statement Request, Priority: 3] -> [ID: 101, Service: Deposit, Priority: 2] -> [ID: 103, Service: Account Opening, Priority: 1] -> NULL

--- Another VIP Arrives ---

Customer Enqueued -> ID: 202, Service: Premium Customer, Priority: 9 (High Priority - moved to front)

--- Current Queue ---
[ID: 202, Service: Premium Customer, Priority: 9] -> [ID: 105, Service: Credit Card, Priority: 6] -> [ID: 102, Service: Withdrawal, Priority: 4] -> [ID: 106, Service: Statement Request, Priority: 3] -> [ID: 101, Service: Deposit, Priority: 2] -> [ID: 103, Service: Account Opening, Priority: 1] -> NULL

--- Testing FIFO within same priority ---

Customer Enqueued -> ID: 107, Service: Normal Query 1, Priority: 2

Customer Enqueued -> ID: 108, Service: Normal Query 2, Priority: 2

Customer Enqueued -> ID: 109, Service: Normal Query 3, Priority: 2

--- Current Queue ---
[ID: 202, Service: Premium Customer, Priority: 9] -> [ID: 105, Service: Credit Card, Priority: 6] -> [ID: 102, Service: Withdrawal, Priority: 4] -> [ID: 106, Service: Statement Request, Priority: 3] -> [ID: 101, Service: Deposit, Priority: 2] -> [ID: 107, Service: Normal Query 1, Priority: 2] -> [ID: 108, Service: Normal Query 2, Priority: 2] -> [ID: 109, Service: Normal Query 3, Priority: 2] -> [ID: 103, Service: Account Opening, Priority: 1] -> NULL

--- Serving All Remaining Customers ---

>>> Serving Customer ID: 202 | Service: Premium Customer | Priority: 9

>>> Serving Customer ID: 105 | Service: Credit Card | Priority: 6

>>> Serving Customer ID: 102 | Service: Withdrawal | Priority: 4

>>> Serving Customer ID: 106 | Service: Statement Request | Priority: 3

>>> Serving Customer ID: 101 | Service: Deposit | Priority: 2

>>> Serving Customer ID: 107 | Service: Normal Query 1 | Priority: 2

>>> Serving Customer ID: 108 | Service: Normal Query 2 | Priority: 2

>>> Serving Customer ID: 109 | Service: Normal Query 3 | Priority: 2

>>> Serving Customer ID: 103 | Service: Account Opening | Priority: 1

--- Attempting to Serve from Empty Queue ---

No Customers in queue....

Queue is empty.

========== Simulation Complete ==========

```