#include <vector>
using namespace std; // avoid std in large codebases since it may lead to conflicts

class Solution {
public:

    int majorElement(vector<int>& nums){
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

        int number = majorElement(nums);
        int counter = 0;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == number) {
                counter++ ;
            }
        }

        if(counter > nums.size()/2){
            return number;
        }
        
        return -1;
    }
};