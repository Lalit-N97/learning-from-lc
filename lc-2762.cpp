/**
Medium - Continuous Subarrays
https://leetcode.com/problems/continuous-subarrays/
Written By : LalitN97
**/

class Solution {
public:
    
    /**
    Idea : 
    we can check at each element whether it should form continuous subarray including that element till its 
    extreme left and count the subarrays using (j - i + 1). 
    Now if the cur element is not forming valid continuous subarray on including it then that element can 
    form the continuous subrray in some smaller subarray from left, that can be identified using min and
    max priority_queues and sliding window of left pointer towards right.
    Time Complexity - O(N*LogN) since n elements are inserted into the queue and poped out of the queue once
    Space Complexity - O(N)
    where N is the size of the input array
    **/
    
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        long long ans = 1; // we have already considered nums[0] as the valid subarray hence tracking it as well in the answer.
        int i = 0;
        int j = 1;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minPQ;
        priority_queue<pair<int, int>> maxPQ;
        minPQ.push(make_pair(nums[0], 0));
        maxPQ.push(make_pair(nums[0], 0));
        
        // until all elements are checked in the nums array we'll iterate over the nums array
        while(j < n){
            int idx = i;
            int curMin = min(minPQ.top().first, nums[j]);
            int curMax = max(maxPQ.top().first, nums[j]);
            if(abs(curMax - curMin) <= 2){
                minPQ.push({nums[j], j});
                maxPQ.push({nums[j], j});
                ans += (j - i + 1);
                j++;
            }
            else{
                while(!minPQ.empty() && (abs(minPQ.top().first - nums[j]) > 2 || minPQ.top().second <= i) ){
                    idx = max(idx, minPQ.top().second + 1);
                    minPQ.pop();
                }
                
                while(!maxPQ.empty() && (abs(maxPQ.top().first - nums[j]) > 2 || maxPQ.top().second <= i)){
                    idx = max(idx, maxPQ.top().second + 1);
                    maxPQ.pop();
                }
                i = idx;  
                if(i == j){
                    minPQ.push({nums[j], j});
                    maxPQ.push({nums[j], j});
                    ans++;
                    j++;
                }
            }
        }
        return ans;
    }
};