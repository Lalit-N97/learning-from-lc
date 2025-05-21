/**
Easy - Find Target Indices After Sorting Array
https://leetcode.com/problems/find-target-indices-after-sorting-array
Written By : LalitN97
**/

class Solution {
public:

    /**
    Idea : Track the no of less elements than target and no of equal elements to target while iterating.
    Time Complexity - O(N)
    Space Complexity - O(1)
    **/

    vector<int> targetIndices(vector<int>& nums, int target) {
        int nLess = 0;
        int nEqual = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] < target) nLess++;
            else if(nums[i] == target) nEqual++;
        }
        if(nEqual == 0) return {};
        vector<int> ans;
        ans.reserve(nEqual);
        for(int idx = nLess; idx < nLess + nEqual; idx++){
            ans.push_back(idx);
        }
        return ans;
    }
};