#include <vector>
using namespace std; // avoid std in large codebases since it may lead to conflicts

class Solution {
public:

    const int findCandidate(vector<int>& nums){
        int element;
        int count = 0;

        for(int i=0; i<nums.size(); i++){
            if(count == 0){
                count = 1;
                element = nums[i];
            }
            else if(element == nums[i]){
                count++;
            }
            else{
                count--;
            }
        }
        return element;
    }

    int majorityElement(vector<int>& nums) {
        if (nums.empty()) return -1;

        int candidate = findCandidate(nums);
        int counter = 0;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == candidate) {
                counter++ ;
            }
        }

        return (counter > nums.size()/2) ? candidate : -1;
    }
};