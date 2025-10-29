/*

You are part of a university admissions office and need to keep track of the kth highest test score from applicants in real-time. This helps to determine cut-off marks for interviews and admissions dynamically as new applicants submit their scores. You are tasked to implement the given function , for a given integer k, maintains a stream of test scores and continuously returns the kth highest test score after a new score has been submitted. More specifically, we are looking for the kth highest score in the sorted list of all scores.

Implement the KthLargest function and other heap functions:

KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of test scores nums.
int add(int val) Adds a new test score val to the stream and returns the element representing the kth largest element in the pool of test scores so far.
Input Format

First line - Two integers, K and N (where K is the kth largest to find, and N is the number of operations)
Next N lines:
1 followed by the number to insert 🡺 performs insert operation
2 to print the current kth largest element
Constraints

1 <= K <= 100
0 <= N <= 1000
Inserted numbers: -10^4 <= num <= 10^4
Output Format

Output the kth largest element after each 2 operations.
Sample Input 0

3 6
1 4
1 5
2
1 8
2
1 2
Sample Output 0

-1
4
Explanation 0

There are 6 operations in total.

First, K = 3.
1 4 → Insert 4 → Heap: [4] → Less than 3 elements so Kth largest is undefined.
1 5 → Insert 5 → Heap: [4, 5] → Still less than 3.
2 → Output: -1 (Not enough elements yet to determine Kth largest).
1 8 → Insert 8 → Heap: [4, 5, 8] → Now size = 3, Kth largest is min heap top → 4.
2 → Output: 4.
1 2 → Insert 2 → Heap remains [4, 5, 8] → 2 ignored since it’s smaller than current Kth largest (4).

*/



#include <stdio.h>
#define MAX 1000

typedef struct MinHeap { // Parent value < Child value
    int data[MAX];
    int size;
    int k; 
} MinHeap;

void initializeHeap(MinHeap *heap, int k) {
    heap->size = 0;
    heap->k = k;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(MinHeap *heap, int index) {
    int smthg = (index-1)/2;
    while(index>0 && heap->data[smthg]>heap->data[index]){
        swap(&heap->data[index], &heap->data[smthg]);
        index = smthg;
        smthg = (index-1)/2;
    }
}

void heapifyDown(MinHeap *heap, int index) {
    int smol = index;
    int left = 2*index+1;
    int right = 2*index+2;
    
    if(left<heap->size && heap->data[left]<heap->data[smol]){
        smol = left;
    }
    if(right<heap->size && heap->data[right]<heap->data[smol]){
        smol= right;
    }
    
    if(smol!=index){
        swap(&heap->data[index], &heap->data[smol]);
        heapifyDown(heap, smol);
    }
}

void insert(MinHeap *heap, int num) {
    if(heap->size < heap->k){
    heap->data[heap->size] = num;
    heap->size++;
    heapifyUp(heap, heap->size-1);
    }else if (num > heap->data[0]){
        heap->data[0] = num;
        heapifyDown(heap, 0);
    }
}

int getKthLargest(MinHeap *heap) {
    if (heap->size < heap->k)
        return -1;
    return heap->data[0];
}

// Driver code
int main() {
    MinHeap heap;
    int k, n, operation, num, result;
    scanf("%d %d", &k, &n);
    initializeHeap(&heap, k);

    while (n--) {
        scanf("%d", &operation);
        switch (operation) {
            case 1:
                scanf("%d", &num);
                insert(&heap, num);
                break;
            case 2:
                result = getKthLargest(&heap);
                printf("%d\n", result);
                break;
        }
    }
    return 0;
}