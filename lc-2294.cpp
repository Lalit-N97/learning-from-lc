/**
Medium - Partition Array Such That Maximum Difference Is K
https://leetcode.com/problems/partition-array-such-that-maximum-difference-is-k
Written By : LalitN97
**/

class Solution {
public:

    /**

    Idea : Sort the array and iterate over its elements to consider sequences which satisfies the condition.
    Approach : we are going to use counting sort and for first elemtent we store it as the low and using this element we'll get
    1 subsequence, then while iterating over the frequency array consider current element as the high and check if high - low 
    is atmost k. if no, then this current high will be considered in the next subequence (so increase the count) and also 
    make current high as the low for the next subsequence. 
    If it is the other case, then continue checking the conditions.
    Time Complexity - O(N)
    Space Complexity - O(N)
    where N is the size of the input array.
    */

    int partitionArray(vector<int>& nums, int k) {
        int freq[100001];
        memset(freq, 0, sizeof freq);
        int minm = INT_MAX;
        int maxm = INT_MIN;
        for(int num : nums) {
            minm = min(minm, num);
            maxm = max(maxm, num);
            freq[num]++;
        }
        int low = minm;
        freq[low]--;
        int nSubsequences = 1;
        for(int i = minm; i <= maxm; i++){
            if(freq[i] > 0){
                if(i - low > k){
                    nSubsequences++;
                    low = i;
                }
                freq[i]--;
            }
        }
        return nSubsequences;
    }
};