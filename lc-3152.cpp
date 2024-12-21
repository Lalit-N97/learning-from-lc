/**
Medium - Special Array II
https://leetcode.com/problems/special-array-ii/
Written By : LalitN97
**/

class Solution {
public:
    
    /**
    Idea : 
    take a prefix sum of array where arr[i] stores nums[i] and nums[i - 1] has different parity or not
    use that prefix sum to query in O(1)
    Time Complexity - O(N + Q)
    Space Complexity - O(N)
    where N is the size of input array and Q is the number of queries
    **/
    
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        // int *prefixSum = new int[n+1];
        int prefixSum[100002] = {0};
        for(int i = 1; i < n; i++) prefixSum[i] = prefixSum[i - 1] + !((nums[i] ^ nums[i - 1]) & 1);
        vector<bool> ans(queries.size());
        int i = 0;
        for(vector<int> query : queries){
            ans[i++] = (prefixSum[query[1]] - prefixSum[query[0]]) == 0;
        }
        return ans;
    }
};