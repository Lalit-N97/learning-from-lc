/**
Easy - Special Array I
https://leetcode.com/problems/special-array-i
Written By : LalitN97
**/

class Solution {
public:

    /**
    Idea : for a single element you will always return true;
    for mulitple elements iterate over the array starting from 1st index tracking current and previous element
    and return false if currrent and prev element has the same parity by checking both odd or both even
    condition using bitmasking.
    Time Complexity - O(N)
    Space Complexity - O(1)
    where N is the size of the input array
    **/
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return true;
        for(int i = 1; i < n; i++){
            int prev = nums[i - 1];
            int cur = nums[i];
            if( !((prev & 1)  ^ (cur & 1))) return false;
        }
        return true;
    }
};