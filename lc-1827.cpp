/**
Easy - Minimum Operations to Make the Array Increasing
https://leetcode.com/problems/minimum-operations-to-make-the-array-increasing/
Author : LalitN97
**/

class Solution {
public:
    
    /**
    Logic : 
    If input array contains only 1 element then we'll get 0 operations
    If input array contains many elements then iterate over the elements and with each iteration get the maxximum element among the two (last element + 1) and the current element. And get ehe differnce of min operations while iterating over the array elements
    Time Complexity - O(N)
    Space Complexity - O(1)
    **/
    
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        int minOperations = 0;
        int nextMinEle = nums[0];
        for(int i = 1; i < n; i++){
            nextMinEle = max(nextMinEle + 1, nums[i]);
            minOperations += ((nextMinEle - nums[i]) > 0) ? (nextMinEle - nums[i]) : 0;
        }
        return minOperations;
    }
};