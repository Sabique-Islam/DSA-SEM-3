
---

## 1. Recursive Functions

### Function to compute the maximum element of an array

```c
max(int *a, int n)
// a is pointer to an array, n is the index of the last element
{
  if(n==0)
    return a[0];
  else
    m = max(a, n-1);
  if(a[n] > m)
    return a[n];
  else
    return m;
}
```

### Function to compute the minimum element of an array

```c
min(int *a, int n)
// a is pointer to an array, n is the index of the last element
{
  if(n==0)
    return a[0];
  else
    m = min(a, n-1);
  if(a[n] < m)
    return a[n];
  else
    return m;
}
```

### Function to compute the sum of elements of an array

```c
sum(int *a, int n)
// a is pointer to an array, n is the index of the last element
{
  if(n==0)
    return a[0];
  else
    return (a[n] + sum(a,n-1));
}
```

### Function to compute the product of elements of an array

```c
product(int *a, int n)
// a is pointer to an array, n is the index of the last element
{
  if(n==0)
    return a[0];
  else
    return (a[n] * product(a,n-1));
}
```

### Function to compute the average of elements of an array

```c
average(int *a, int n, int i)
// a is pointer to an array, i is the index of the element, n is the number of elements
{
  if(i==n-1)
    return (a[i]/n);
  else
    a = a[i]/n + average(a, i+1, n);
  return a;
}
```

---

## 2. Evaluate using recursive definitions

* **6 !**

  ```
  6! = 6 * 5!
  5! = 5 * 4!
  4! = 4 * 3!
  3! = 3 * 2!
  2! = 2 * 1!
  1! = 1
  ```

  Therefore:

  ```
  2! = 2 * 1 = 2
  3! = 3 * 2 = 6
  4! = 4 * 6 = 24
  5! = 5 * 24 = 120
  6! = 6 * 120 = 720
  ```

* **9 !**

  ```
  9! = 9 * 8!
  ```

* **100 \* 3**

  Using

  ```
  a * b = a if b=1
  a * b = a + a * (b-1) if b>1
  ```

  ```
  100 * 3
  = 100 + 100 * (3-1)
  = 100 + 100 * 2
  100 * 2 = 100 + 100 * (2-1)
          = 100 + 100 * 1
  100 * 1 = 100
  100 * 2 = 100 + 100 = 200
  100 * 3 = 100 + 200 = 300
  ```

* **6 \* 4**

  ```
  6 * 4 = 6 + 6 * 3
  ```

* **fib(10), fib(11)**
  Using:

  ```
  fib(n) = n if n=0 or n=1
  fib(n) = fib(n-2) + fib(n-1)
  ```

  ```
  fib(10) = fib(8) + fib(9)
  fib(11) = fib(9) + fib(10)
  ```

---

## 3. Determine what the recursive function computes

```c
int func(int n)
{
  if(n==0)
    return 0;
  return (n + func(n-1));
}
```

**Solution:** It computes `0 + 1 + 2 + … + n`.

---

## 4. Transform to Prefix & Postfix

1. **A + B - C**

   * Postfix: `AB+C-`
   * Prefix: `- C + A B`

2. **(A + B) \* (C - D) \$ E \* F**

   * Postfix: `AB+CD-*E$*F`
   * Prefix: `* $ * +AB -CD EF`

3. **(A + B) \* (C \$ (D - E) + F) - G**

   * Postfix: `AB+ CDE- $F+ * G-`
   * Prefix: `- * +AB + $C -DE F G`

4. **A + (((B - C) \* (D - E) + F) / G) \$ (H - J)**
   *(not expanded fully in solution)*

---

## 5. Deque as Linked List

Routines: `insrtleft`, `insrtright`, `remvleft`, `remvright`

```c
void qinsert_left(int x, struct dequeue *dq) { ... }
void qinsert_right(int x, struct dequeue *dq) { ... }
int qremv_left(struct dequeue *dq) { ... }
int qremv_right(struct dequeue *dq) { ... }
void qdisplay(struct dequeue dq) { ... }
```

*(full code already given in solution)*

---

## 6. Ascending Priority Queue (Array Implementation)

Operations: `pqinsert`, `pqmindelete`, `empty`

```c
struct pqueue pqmindelete(struct pqueue *pq,int *count) { ... }
void pqinsert(int x,int pty,struct pqueue* pq,int *count) { ... }
void qdisplay(struct pqueue *q, int count) { ... }
```

---

## 7. Linked Stack Implementation

Operations: `empty`, `push`, `pop`

```c
int empty(struct node *top) { ... }
void push(int x, struct node **p) { ... }
int pop(struct node **p) { ... }
void display(struct node *p) { ... }
```

---

## 8. Linked Queue Implementation

Operations: `empty`, `insert`, `remove`

```c
void insert(int x, struct node **f, struct node **r) { ... }
int remove(struct node **f, struct node **r) { ... }
void qdisplay(struct node *f, struct node *r) { ... }
int empty(struct node *f) { ... }
```

---

## 9. Linked Priority Queue Implementation

Operations: `empty`, `pqinsert`, `pqmindelete`

```c
void pqinsert(int x, int y) { ... }
int pqmindelete() { ... }
void qdisplay() { ... }
```

---
