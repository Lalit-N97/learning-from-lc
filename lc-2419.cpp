// https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        /**
           Logic : 
           if you have distinct numbers then take any number bitwise AND with the maximum number will reduce the result
           So the maximum value of Bitwise AND in distinct set of number will the maximum number of that set.
           Now to find the longest subarray with maximum bitwise AND - we can find the maximum number in the array
           and calculate the length of longest subarray which has same numbers as that of maximum number value.
           Time Complexity - O(N), Space Complexity - O(1)
        **/  
        
        int maxm = INT_MIN;
        for(int num : nums){
            maxm = max(maxm, num);
        }
        
        // now find count consecutive numbers with value same as that maxm
        int maxLen = 0;
        int count = 0;
        for(int num : nums){
            if(num != maxm) count = 0;
            else count++;
            maxLen = max(maxLen, count);
        }
        
        return maxLen;
    }
};