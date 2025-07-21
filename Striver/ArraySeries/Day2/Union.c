#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool exists(int* arr, int size, int val) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == val) return true;
    }
    return false;
}

int* unionArrays(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int capacity = nums1Size + nums2Size;
    int* result = (int*)malloc(capacity * sizeof(int));
    int index = 0;

    for (int i = 0; i < nums1Size; i++) {
        if (!exists(result, index, nums1[i])) {
            result[index++] = nums1[i];
        }
    }

    for (int j = 0; j < nums2Size; j++) {
        if (!exists(result, index, nums2[j])) {
            result[index++] = nums2[j];
        }
    }

    *returnSize = index;
    return result;
}

int main() {
    int nums1[] = {1, 2, 3};
    int nums2[] = {3, 4, 5, 6};
    int returnSize;

    int* result = unionArrays(nums1, 3, nums2, 4, &returnSize);

    printf("Union of arrays: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    return 0;
}