#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> leaders(vector<int>& arr) {
    int n = arr.size();
    vector<int> result;
    int maxRight = INT_MIN;

    for (int i=n-1; i>=0; i--) {
        if (arr[i] > maxRight) {
            result.push_back(arr[i]);
            maxRight = arr[i];
        }
    }
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    vector<int> arr = {1, 2, 5, 3, 1, 2};
    vector<int> answer = leaders(arr);

    cout << "Leaders: ";
    for (int val : answer) {
        cout << val << " ";
    }
    cout << "\n";

    return 0;
}