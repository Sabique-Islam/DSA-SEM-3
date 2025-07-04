#include <iostream>
#include <climits>

using namespace std;

class Solution{
public:
    int reverse(int x) {
        int result = 0;
        while (x != 0) {
            int carry = x % 10;
            if (result > INT_MAX / 10 || (result < INT_MIN / 10))
                return 0;

            result = result * 10 + carry;
            x /= 10;
        }
        return result;
    }
};