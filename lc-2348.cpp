/**
Medium - Number of Zero-Filled Subarrays
https://leetcode.com/problems/number-of-zero-filled-subarrays
Written By : LalitN97
**/

class Solution {
public:

    /**
    Idea : if we have a continuous zeros from i to j then the count of all the subarrays are (j - i + 1) * (j - i + 2)/2
    Now we need to iterate over the array such that whenever we encounter a zero we will increment counter by 1
    and whenever we'll encounter non-zero we'll add the valid subarrays from the current counter into our answer and 
    then reset the counter to 0. Do this for one more time after the for loop.
    Time Complexity - O(N)
    Space Complexity - O(1)
    where N is the size of the input array. 
    **/

    long long zeroFilledSubarray(vector<int>& nums) {
        long long count = 0;
        long long nValidSubarrays = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0){
                nValidSubarrays += (count * (count + 1))/2;
                count = 0;
            }
            else count++;
        }
        nValidSubarrays += (count * (count + 1))/2;
        return nValidSubarrays;
    }
};