/**
Medium - Rearrange Array Elements by Sign
https://leetcode.com/problems/rearrange-array-elements-by-sign
Written By : LalitN97
**/

class Solution {
public:

    /**
    Idea : we can keep two pointers one track the postive number and other tracking the negative number 
    from left to right order.
    Algorithm : Iterate over the array from left to right and alternatively look for positive and negative
    integers using two pointers one keeping track of positive integer and other keeping track of negative interger
    Keep a flag positiveTurn to switch between postivie and negative number search while iterating.
    Time Complexity - O(N)
    Space Complexity - O(N)
    where N is the size of input array
    **/

    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        int posIdx = 0;
        int negIdx = 0;
        bool positiveTurn = true;
        while(posIdx < n && negIdx < n){
            if(positiveTurn){
                if(nums[posIdx] > 0){
                    ans.push_back(nums[posIdx]);
                    positiveTurn = false;
                }
                posIdx++;
            }
            else{
                if(nums[negIdx] < 0){
                    ans.push_back(nums[negIdx]);
                    positiveTurn = true;
                }
                negIdx++;
            }
        }

        while(negIdx < n && nums[negIdx] > 0) negIdx++;
        if(negIdx < n) ans.push_back(nums[negIdx]);

        return ans;
    }
};