/**
Easy - Concatenation of Array
https://leetcode.com/problems/concatenation-of-array/
Author : LalitN97
**/

class Solution {
public:
    
    /**
    Idea : take a out array of size 2*n and populate its values using nums input vector
    Time Complexity - O(N)
    Space Complexity - O(N)
    where N is the size of input array
    **/
    
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(2*n);
        for(int i = 0; i < n; i++){
            ans[i] = nums[i];
            ans[i + n] = nums[i];
        }
        return ans;
    }
};