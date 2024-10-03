// https://leetcode.com/problems/subarray-sums-divisible-by-k/

class Solution {
public:
    
    /**
    Logic : sum of any subarray % k should be equal to 0 i.e. sum(i, j) % k = 0 i.e. sum(i) % k = sum(j) % k.
    Negative prefix sum can be handled using (sum(i) % k + k) % k, if sum(i) is negative
    Using prefix sum we can achieve this
    Time Complexity - O(N + k), Space Complexity - O(N) 
    **/
    
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int prefixSum[30001];
        memset(prefixSum, 0, sizeof prefixSum);
        for(int i = 0; i < n; i++) prefixSum[i + 1] = prefixSum[i] + nums[i];
        int freq[10001];
        memset(freq, 0, sizeof freq);
        for(int i = 1; i <= n; i++){
            int num = ((prefixSum[i] % k) + k)%k; 
            freq[num]++;
        }
        int subArrCount = freq[0];
        for(int i = 0; i <= k; i++){
            subArrCount += (freq[i] * (freq[i] - 1)) / 2;
        }
        
        return subArrCount;
    }
};