/**
Medium - Longest Nice Subarray
https://leetcode.com/problems/longest-nice-subarray
Written By : LalitN97
**/


class Solution {
public:

    /**
    Idea : we need to take two pointers to iterate over the nums array which will consider shrinking and expanding
    the window between two pointers based on satisfying the conditions.
    Get the cummulative set bits in the current window using OR operation. 
    Perform Bitwise AND with the upcoming element. If result is 0 expand the window by considering the next element 
    and cummulate its set bits in a common variable and if the result is not 0 then shrink the window by removing
    first element of window using XOR operation on cummulative set bits with the first element.
    Time Complexity - O(2*N)
    Space Complexity - O(1)
    where N is the size of the input array.
    **/

    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        int end = 0;
        int cummulativeSetBits = nums[end];
        int maxLen = 1;
        while(end < n - 1){
            if((cummulativeSetBits & nums[end + 1]) == 0) {
                end++;
                cummulativeSetBits |= nums[end];
                maxLen = max(maxLen, end - start + 1);
            }
            else{
                cummulativeSetBits ^= nums[start];
                start++;
            }
        }
        return maxLen;
    }
};