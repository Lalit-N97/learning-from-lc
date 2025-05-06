/**
Easy - Build Array from Permutation
https://leetcode.com/problems/build-array-from-permutation
Written By : LalitN97
**/

class Solution {
public:

    /**
    Idea : we can store two values at one integer by decoding and encoding the nums in the decimal number system.
    i.e. storing 9 and 2 at one number can look like this -> 9000002
    so to fetch 9 divide it by 10^6 and to fetch 2 divide the given num by 10^6 (same base)
    Approach : Since our constraints on num are below 1000. so we can use base system of 1000 to store final
    and the previous value in the given nums array.
    Time Complexity - O(N)
    Space Complexity - O(1)
    where N is the size of input array nums
    **/

    vector<int> buildArray(vector<int>& nums) {
        const int BASE = 1000;
        for(int i = 0; i < nums.size(); i++){
            nums[i] += BASE * (nums[nums[i]] % BASE); //here final value is starting from MSB and previous value is at LSB
        }

        for(int i = 0; i < nums.size(); i++){
            nums[i] /= BASE;
        }
        return nums;
    }
};