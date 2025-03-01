/**
Easy - Apply Operations to an Array
https://leetcode.com/problems/apply-operations-to-an-array
Written By : LalitN97
**/

class Solution {
public:

    /**
    Idea : iterate over the input array one by one n - 1 times.
    check if the condition nums[i] == nums[i - 1] satisfies then perform the operation.
    Keept track of first zero element to be replaced with non-zero element. This is to keep all the 
    non-zero elements at the left.
    Time Complexity - O(N)
    Space COmplexity - O(1)
    where N is the size of input array
    **/

    vector<int> applyOperations(vector<int>& nums) {
        int zeroPtr = -1;
        int n = nums.size();
        for(int i = 0; i < n - 1; i++){
            if(nums[i] == 0 && zeroPtr == -1) zeroPtr = i;
            if(nums[i] != 0 && nums[i] == nums[i + 1]){
                nums[i] <<= 1;
                nums[i + 1] = 0;
                if(zeroPtr != -1) {
                    swap(nums[zeroPtr], nums[i]);
                    zeroPtr++;
                }
            }
            else if(nums[i] != 0){
                if(zeroPtr != -1) {
                    swap(nums[zeroPtr], nums[i]);
                    zeroPtr++;
                }
            }
        }

        if(zeroPtr != -1) {
            swap(nums[zeroPtr], nums[n - 1]);
            zeroPtr++;
        }

        return nums;
    }
};
