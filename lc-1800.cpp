/**
Easy - Maximum Ascending Subarray Sum
https://leetcode.com/problems/maximum-ascending-subarray-sum/
Author : LalitN97
**/

class Solution {
public:
    
    /**
    keep a variable sum which will hold the sum upto some point (sub array sum) in the array
    intialize the variable with first element of array
    iterate over the array and see if the current element is greater than previous element then add that element in the sum
    otherwise assign current element in the sum
    Time Complexity - O(N)
    Space Complexity - O(1)
    **/
    
    int maxAscendingSum(vector<int>& nums) {
        int sum = nums[0];
        int maxSubarraySum = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > nums[i - 1]) sum += nums[i];
            else {
                maxSubarraySum = max(maxSubarraySum, sum);
                sum = nums[i];
            }
        }
        maxSubarraySum = max(maxSubarraySum, sum);
        return maxSubarraySum;
    }
};