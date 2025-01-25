/**
Hard - Trapping Rain Water
https://leetcode.com/problems/trapping-rain-water/
Written By : LalitN97
**/

class Solution {
public:

    /**
    Idea : identify the amount of water stored at the top of each building height. For a current building 
    the water will only be stored if the min of (max building height in the left and the right) is greater or equal
    to the current building height.
    Though we use the prefixSum patter to identify all indices prefixMax and SuffixMax but they can also be 
    find out by stack next greater element approach where we should not stop at the next greater element but 
    keep moving until we found the gratest element on the left/right.
    Time Complexity - O(N)
    Space Complexity - O(N)
    **/

    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> prefixMax(n, 0);
        vector<int> suffixMax(n, 0);
        prefixMax[0] = height[0];
        suffixMax[n - 1] = height[n - 1];
        for(int i = 1; i < n; i++){
            prefixMax[i] = max(prefixMax[i - 1], height[i]);
            suffixMax[n - i - 1] = max(suffixMax[n - i], height[n - i - 1]);
        }
        int waterTrapped = 0;
        for(int i = 1; i < n - 1; i++){
            int diff = min(prefixMax[i - 1], suffixMax[i + 1]) - height[i];
            waterTrapped += (diff <= 0 ? 0 : diff);
        }
        return waterTrapped;
    }
};