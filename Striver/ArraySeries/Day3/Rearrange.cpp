#include <vector>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int size = nums.size();
        vector <int> result(size, 0);

        int posIndex = 0, negIndex = 1;

        for(int i=0; i<size; i++){
            if(nums[i]<0){
                result[negIndex] = nums[i];
                negIndex += 2;
            }else{  
                result[posIndex] = nums[i];
                posIndex += 2;
            }
        }
        return result;
    }
};