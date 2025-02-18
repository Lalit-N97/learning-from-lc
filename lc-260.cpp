/**
Medium - Single Number III
https://leetcode.com/problems/single-number-iii
Written By : LalitN97
**/

class Solution {
public:

    /**
    Idea : use the bitmasking trick where xor of two same elements is 0.
    Take the xor of all elements which will results into xor of x and y. which we need to find out.
    Group all the elements into two sets for which one set has ith bit set and other set has ith bit unset.
    The ith bit is the first distinct bit in the resultant xor of x and y when iterating from least 
    significant bit to most significant bit.
    Time Complexity - O(N)
    Space Complexity - O(1)
    where N is the size of input string
    **/

    vector<int> singleNumber(vector<int>& nums) {
        int xorXY = 0;
        for(int num : nums) xorXY ^= num;
        int idx = 0;
        while((xorXY & 1) == 0){
            idx++;
            xorXY >>= 1;
        }
        int X = 0;
        int Y = 0;
        for(int num : nums){
            if(num & (1 << idx)){
                X ^= num;
            }
            else Y ^= num;
        }
        return {X, Y};
    }
};