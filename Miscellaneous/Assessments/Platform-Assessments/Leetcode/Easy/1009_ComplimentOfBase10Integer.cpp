#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        int i = 0;
        int result = 0;
        while(n){
            int bit = n&1;
            bit = bit^1; // XOR
            result += bit*pow(2,i);
            n = n>>1;
            i++;
        }
        return result;
    }
};