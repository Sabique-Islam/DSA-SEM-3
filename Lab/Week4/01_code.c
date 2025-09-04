#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The struct to hold the queue's data and state
typedef struct {
    int* data;
    int size;
    int capacity;
} FrontMiddleBackQueue;

// A reasonable starting capacity
#define INITIAL_CAPACITY 8

// Creates and initializes the queue object.
FrontMiddleBackQueue* frontMiddleBackQueueCreate() {
    FrontMiddleBackQueue* obj = (FrontMiddleBackQueue*)malloc(sizeof(FrontMiddleBackQueue));
    obj->capacity = INITIAL_CAPACITY;
    obj->data = (int*)malloc(sizeof(int) * obj->capacity);
    obj->size = 0;
    return obj;
}

// Helper function to double the array's capacity when it's full.
void ensureCapacity(FrontMiddleBackQueue* obj) {
    if (obj->size >= obj->capacity) {
        obj->capacity *= 2;
        obj->data = (int*)realloc(obj->data, sizeof(int) * obj->capacity);
    }
}

// Adds a value to the front of the queue. 
void frontMiddleBackQueuePushFront(FrontMiddleBackQueue* obj, int val) { 
    ensureCapacity(obj);
    
    for (int i = obj->size-1; i >= 0; i--){
        obj->data[i+1] = obj->data[i];
    }
    
    obj->data[0] = val;
    obj->size++;
    
}

// Adds a value to the middle of the queue. 
void frontMiddleBackQueuePushMiddle(FrontMiddleBackQueue* obj, int val) { 
    ensureCapacity(obj);
	int mid = obj->size/2;
    
    for (int i = obj->size-1; i >= mid; i--){
        obj->data[i+1] = obj->data[i];
    }
    
    obj->data[mid] = val;
    obj->size++;
}

// Adds a value to the back of the queue.
void frontMiddleBackQueuePushBack(FrontMiddleBackQueue* obj, int val) {
 	ensureCapacity(obj);
    
    obj->data[obj->size] = val;
    obj->size++;
}

// Removes and returns the front element.
int frontMiddleBackQueuePopFront(FrontMiddleBackQueue* obj) {
    if (obj->size == 0){
        return -1;
    }
    
    int temp = obj->data[0];
    
    for (int i = 0; i < obj->size-1; i++){
        obj->data[i] = obj->data[i+1];
    }
    
    obj->size--;
    
    return temp;
}

// Removes and returns the middle element.
int frontMiddleBackQueuePopMiddle(FrontMiddleBackQueue* obj) {
    if (obj->size == 0){
        return -1;
    }

	int mid = (obj->size-1)/2;
    int temp = obj->data[mid];
    
    for (int i = mid; i < obj->size-1; i++)
        obj->data[i] = obj->data[i+1];
    
    obj->size--;
    
	return temp;
}

// Removes and returns the back element.
int frontMiddleBackQueuePopBack(FrontMiddleBackQueue* obj) {
	if (obj->size == 0){
        return -1;
    }
    
    int temp = obj->data[obj->size-1];
    
    obj->size--;
    
    return temp;
}

// Frees the allocated memory to prevent leaks.
void frontMiddleBackQueueFree(FrontMiddleBackQueue* obj) {
    free(obj->data);
    free(obj);
}

// Main function to derive the program from standard input
int main() {
    FrontMiddleBackQueue* q = frontMiddleBackQueueCreate();
    int n;
    scanf("%d", &n);

    char command_line[30];
    int value;

    // Loop for each operation
    for (int i = 0; i < n; i++) {
        scanf("%s", command_line);

        if (strstr(command_line, "pushFront")) {
            sscanf(command_line, "%*[^(](%d)", &value);
            frontMiddleBackQueuePushFront(q, value);
        } else if (strstr(command_line, "pushMiddle")) {
            sscanf(command_line, "%*[^(](%d)", &value);
            frontMiddleBackQueuePushMiddle(q, value);
        } else if (strstr(command_line, "pushBack")) {
            sscanf(command_line, "%*[^(](%d)", &value);
            frontMiddleBackQueuePushBack(q, value);
        } else if (strstr(command_line, "popFront")) {
            printf("%d\n", frontMiddleBackQueuePopFront(q));
        } else if (strstr(command_line, "popMiddle")) {
            printf("%d\n", frontMiddleBackQueuePopMiddle(q));
        } else if (strstr(command_line, "popBack")) {
            printf("%d\n", frontMiddleBackQueuePopBack(q));
        }
    }

    frontMiddleBackQueueFree(q);
    return 0;
}