// https://leetcode.com/problems/degree-of-an-array/

class Solution {
public:
    
    // Time Complexity - O(N), Space Complexity - O(N)
    
    int findShortestSubArray(vector<int>& nums) {
        int n = nums.size();
        int freq[50000];
        int firstIdx[50000];
        int lastIdx[50000];
        fill(freq, freq + 50000, 0);
        fill(firstIdx, firstIdx + 50000, -1);
        fill(lastIdx, lastIdx + 50000, -1);
        int maxFreq = INT_MIN;
        for(int i = 0; i < n; i++) {
            if(freq[nums[i]] == 0) firstIdx[nums[i]] = i;
            freq[nums[i]]++;
            maxFreq = max(freq[nums[i]], maxFreq);
            lastIdx[nums[i]] = i;
        }
        int shortestLen = INT_MAX;
        int count = 0;
        for(int i = 0; i < n; i++){
            if(freq[nums[i]] == maxFreq){
                shortestLen = min(shortestLen, lastIdx[nums[i]] - firstIdx[nums[i]] + 1);
            }
        }
        return shortestLen;
    }
};