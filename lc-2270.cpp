/**
Medium - Number of Ways to Split Array
https://leetcode.com/problems/number-of-ways-to-split-array/description/
Written By : LalitN97
**/

class Solution {
public:

    /**
    Two pass solution : 
    In the first pass take total sum of the input array.
    In the second pass - iterate over the input array and at each point from 0 to n - 2 index calculate
    that ith index contains a valid split by tracking the prefixSum and remaning sum can be find out using
    totalSum - prefixSum.
    Time Complexity - O(N)
    Space Complexity - O(1)

    **/

    int waysToSplitArray(vector<int>& nums) {
        long long totalSum = 0;
        for(int num : nums) totalSum += num;

        int nValidSplits = 0;
        long long prefixSum = 0;
        int n = nums.size();
        for(int i = 0; i < n - 1; i++){
            prefixSum += nums[i];
            if(prefixSum >= (totalSum - prefixSum)) nValidSplits++;
        }
        return nValidSplits;
    }
};