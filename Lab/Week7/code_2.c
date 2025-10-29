#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

typedef struct MinHeap {
    int sum[MAX];
    int u[MAX];
    int v[MAX];
    int size;
    int k;
} MinHeap;

void initializeHeap(MinHeap *heap, int k) {
    heap->size = 0;
    heap->k = k;
}

void swap(MinHeap *heap, int i, int j) {
    int temp1 = heap->sum[i];
    int temp2 = heap->u[i];
    int temp3 = heap->v[i];
    
    heap->sum[i] = heap->sum[j];
    heap->u[i] = heap->u[j];
    heap->v[i] = heap->v[j];
    
    heap->sum[j] = temp1;
    heap->u[j] = temp2;
    heap->v[j] = temp3;
}

void heapifyUp(MinHeap *heap, int index) {
    int smthg = (index-1)/2;
    while(index>0 && heap->sum[smthg]>heap->sum[index]){
        swap(heap, index, smthg);
        index = smthg;
        smthg = (index-1)/2;
    }
}

void heapifyDown(MinHeap *heap, int index) {
    int smol = index;
    int left = 2*index+1;
    int right = 2*index+2;
    
    if(left<heap->size && heap->sum[left]<heap->sum[smol]){
        smol = left;
    }
    if(right<heap->size && heap->sum[right]<heap->sum[smol]){
        smol= right;
    }
    
    if(smol!=index){
        swap(heap, index, smol);
        heapifyDown(heap, smol);
    }
}

void push(MinHeap *heap, int u, int v, int sum) {
    if (heap->size < heap->k){
    heap->sum[heap->size] = sum;
    heap->u[heap->size] = u;
    heap->v[heap->size] = v;
    
    heap->size++;
    heapifyUp(heap, heap->size-1);
    }else if(sum < heap->sum[0]){
        heap->sum[0] = sum;
        heap->u[0] = u;
        heap->v[0] = v;
        
        heapifyDown(heap, 0);
    }
}

void pop(MinHeap *heap) {
    if (heap->size == 0){
       exit(1);
    }
    heap->sum[0] = heap->sum[heap->size-1];
    heap->u[0] = heap->u[heap->size-1];
    heap->v[0] = heap->v[heap->size-1];
    
    heap->size--;
    heapifyDown(heap, 0);
    
}

// Driver code
int main() {
    int nums1[MAX], nums2[MAX];
    int n1, n2, k;
    MinHeap heap;

    scanf("%d %d", &n1, &n2);
    for (int i = 0; i < n1; i++) scanf("%d", &nums1[i]);
    for (int i = 0; i < n2; i++) scanf("%d", &nums2[i]);
    scanf("%d", &k);

    initializeHeap(&heap, k);

    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            push(&heap, nums1[i], nums2[j], nums1[i] + nums2[j]);
        }
    }

    for (int i = 0; i < k && heap.size > 0; i++) {
        printf("%d %d\n", heap.u[0], heap.v[0]);
        pop(&heap);
    }

    return 0;
}