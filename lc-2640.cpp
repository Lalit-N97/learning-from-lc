/**
Medium - Find the Score of All Prefixes of an Array
https://leetcode.com/problems/find-the-score-of-all-prefixes-of-an-array
Written By : LalitN97
**/

class Solution {
public:

    /**
    Idea : we don't need storage for conver array, rather we can dynamically store the current value of conver[i]
    while iterating over the nums array by tracking the maximum upto certain point i.
    To find the score at a point i, we need to store its previous score and then add it to the conver[i] value.
    Time Complexity - O(N)
    Space Complexity - O(N)
    where N is the size of input array
    **/

    vector<long long> findPrefixScore(vector<int>& nums) {
        int n = nums.size();
        int maxm = -1;
        vector<long long> result(n);
        for(int i = 0; i < n; i++){
            maxm = max(maxm, nums[i]);
            if(i == 0) result[i] = nums[i] + maxm;
            else result[i] = result[i - 1] + nums[i] + maxm;
        }
        return result;
    }
};