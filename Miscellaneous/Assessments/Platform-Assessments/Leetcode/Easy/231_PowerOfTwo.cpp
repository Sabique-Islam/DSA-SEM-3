#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        int result = 1;
        for(int i=0; i<=30; i++){
            if(result == n){
                return true;
            }
            if(result<INT_MAX/2)
            result *= 2;
        }
        return false;
    }
};