/**
Easy - Longest Strictly Increasing or Strictly Decreasing Subarray
https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray
Written By : LalitN97
**/

class Solution {
public:

    /**
    Idea : Iterate over the nums array and check adjacent elements for increasing and decreasing sequence
    and track their maximum length.
    Specifically for every i >= 1, check if the prev adjacent element forms a increasing/decreasing/equal sequence
    thus tracking the longest increasing/decreasing sequence while iterating. Reset the increasing length, if found
    a decreasing sequence beginning and vice versa for reseting dereasing length.
    Time Complexity - O(N)
    Space Complexity - O(1)
    **/ 

    int longestMonotonicSubarray(vector<int>& nums) {
        int incrLen = 1;
        int decrLen = 1;
        int maxLen = 1;
        int i = 1;
        int n = nums.size();
        while(i < n){
            if(nums[i] > nums[i - 1]){
                decrLen = 1;
                incrLen++;
            }
            else if(nums[i] < nums[i - 1]){
                incrLen = 1;
                decrLen++;
            }
            else{
                incrLen = 1;
                decrLen = 1;
            }
            i++;
            maxLen = max(incrLen, max(maxLen, decrLen));
        }
        return maxLen;
    }
};