/**
Easy - Get Maximum in Generated Array
https://leetcode.com/problems/get-maximum-in-generated-array/description/
Written By : LalitN97
**/

class Solution {
public:

    /**
    Idea : while iterating from 2 to n store the cur values in an array to retrieve the old values
    when required.
    nums[i] = i for 0 <= n <= 1
    nums[i] = nums[i/2] for all even values of n >= 2
    nums[i] = nums[(i - 1)/2] + nums[((i - 1)/2) + 1] for all odd values where n >= 2
    **/

    int getMaximumGenerated(int n) {
        int nums[101];
        memset(nums, 0, sizeof nums);
        nums[1] = 1;
        int maxm = 1;
        for(int i = 2; i <= n; i++) {
            if(i & 1) {
                nums[i] = nums[(i - 1)/2] + nums[((i - 1)/2) + 1];
            }
            else{
                nums[i] = nums[i/2];
            }
            maxm = max(maxm, nums[i]);
        }
        return n == 0 ? 0 : maxm;
    }
};