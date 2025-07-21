#include <iostream>
using namespace std;

void leftRotate(int arr[], int d, int n) {
    reverse(arr, arr + d);
    reverse(arr + d, arr + n);
    reverse(arr, arr + n);
}