/**
Easy - Merge Two 2D Arrays by Summing Values
https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values
Written By : LalitN97
**/

class Solution {
public:

    /**
    Idea : take new vector and simulate the process using two pointers - one pointing to nums1 and other pointing
    to nums2. 
    Time Complexity - O(N1 + N2)
    Space Complexity - O(N1 + N2)
    where N1 is the size of nums1 and N2 is the size of nums2 input arrays.
    **/

    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> ans;
        int n = nums1.size();
        int m = nums2.size();
        int i = 0;
        int j = 0;
        while(i < n && j < m){
            int id1 = nums1[i][0];
            int id2 = nums2[j][0];
            int v1 = nums1[i][1];
            int v2 = nums2[j][1];
            if(id1 == id2) {
                ans.push_back({id1, v1 + v2});
                i++;
                j++;
            }
            else if(id1 > id2) {
                ans.push_back({id2, v2});
                j++;
            }
            else {
                ans.push_back({id1, v1});
                i++;
            }
        }

        while(i < n){
            ans.push_back(nums1[i]);
            i++;
        }

        while(j < m){
            ans.push_back(nums2[j]);
            j++;
        }

        return ans;
    }
};