#include <iostream>

using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int freq[2001] = {0};
        int count[1001] = {0};

        for (int i = 0; i < arr.size(); i++) {
            freq[arr[i] + 1000]++;
        }

        for (int i = 0; i < 2001; i++) {
            if (freq[i] > 0) {
                if (count[freq[i]] == 1) {
                    return false;
                }
                count[freq[i]] = 1;
            }
        }
        return true;
    }
};