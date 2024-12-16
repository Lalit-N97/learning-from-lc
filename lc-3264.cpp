/**
Easy - Final Array State After K Multiplication Operations I
https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-i/
Written By : LalitN97
**/

class Solution {
public:
    
    /**
    Idea : 
    solution can be achievable using minHeap of pair of (element, its index).
    Apply the operation k times.
    Time Complexity - O(K*logN)
    Space Complexity - O(N);
    where N is the size of input array
    **/
    
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for(int i = 0; i < nums.size(); i++){
            minHeap.push({nums[i], i});
        }
        
        while(k--){
            pair<int, int> topEle = minHeap.top(); minHeap.pop();
            minHeap.push({topEle.first * multiplier, topEle.second});
        }
        
        vector<int> ans(nums);
        while(!minHeap.empty()){
            ans[minHeap.top().second] = minHeap.top().first;
            minHeap.pop();
        }
        return ans;
    }
};