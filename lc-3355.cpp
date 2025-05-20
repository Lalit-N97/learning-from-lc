/**
Medium - Zero Array Transformation I
https://leetcode.com/problems/zero-array-transformation-i
Written By : LalitN97
**/

class Solution {
public:

    /**
    Idea : line sweap using commulative sum on queries
    Time Complexity - O(N)
    Space Complexity - O(N)
    where N is the size of the input array.
    **/

    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int prefixSum[100002];
        memset(prefixSum, 0, sizeof prefixSum);
        for(vector<int> query : queries){
            int left = query[0];
            int right = query[1];
            prefixSum[left + 1]++;
            prefixSum[right + 2]--;
        }
        for(int i = 0; i < n; i++){
            prefixSum[i + 1] += prefixSum[i];
            if(prefixSum[i + 1] < nums[i]) return false;
        }
        return true;
    }
};