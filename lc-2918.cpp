/**
Medium - Minimum Equal Sum of Two Arrays After Replacing Zeros
https://leetcode.com/problems/minimum-equal-sum-of-two-arrays-after-replacing-zeros
Written By : LalitN97
**/

class Solution {
public:

    /**
    Idea : try getting a range from maximum and minimum sum any array can have by replacing 0 with min value i.e. 1
    and other way to replace 0 with max value i.e. 1000000.
    Once you get a range of sum [min, max] from both array compare if both ranges overlap or not.
    if the ranges don't overlap then return -1 as no minimum sum is possible to exist in both arrays.
    otherwise return the max(min1, min2);
    **/

    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long left1 = 0;
        long long right1 = 0;
        long long left2 = 0;
        long long right2 = 0;
        long long const MAX = 1e12;
        for(int i = 0; i < nums1.size(); i++){
            left1 += (long long)(nums1[i] == 0 ? 1 : nums1[i]);
            right1 += (long long)(nums1[i] == 0 ? MAX : nums1[i]);
        }
        for(int i = 0; i < nums2.size(); i++){
            left2 += (long long)(nums2[i] == 0 ? 1 : nums2[i]);
            right2 += (long long)(nums2[i] == 0 ? MAX : nums2[i]);
        }
        if(left1 > right2 || left2 > right1) return -1; // no overlap
        return max(left1, left2);
    }
};