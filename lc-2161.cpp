/**
Medium - Partition Array According to Given Pivot
https://leetcode.com/problems/partition-array-according-to-given-pivot
Written By : LalitN97
**/

class Solution {
public:

    /**
    Idea : iterate over the array and store each element in different vectors based on less than pivot,
    equal to pivot and greater than pivot.
    Space Complexity - O(N)
    Time Complexity - O(N)
    where N is the size of input array

    Using 3 pointers
    Space Complexity - O(1)
    Time Complexity - O(N)
    where N is the size of input array

    **/

    vector<int> pivotArray(vector<int>& nums, int pivot) {
        // vector<int> less;
        // vector<int> equal;
        // vector<int> greater;
        // vector<int> ans;
        // for(int num : nums){
        //     if(num == pivot) equal.push_back(num);
        //     else if(num < pivot) less.push_back(num);
        //     else greater.push_back(num);
        // }

        // for(int x : less) ans.push_back(x);
        // for(int x : equal) ans.push_back(x);
        // for(int x : greater) ans.push_back(x);
        // return ans;

        int low = 0;
        int same = 0;
        for(int num : nums){
            if(num < pivot) low++;
            else if(num == pivot) same++;
        }
        int high = same + low;
        same = low;
        low = 0;
        vector<int> ans(nums.size());
        for(int num : nums){
            if(num < pivot) ans[low++] = num;
            else if(num == pivot) ans[same++] = num;
            else ans[high++] = num;
        }
        return ans;
    }
};