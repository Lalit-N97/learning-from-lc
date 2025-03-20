/**
Medium - Reduction Operations to Make the Array Elements Equal
https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal
Written By : LalitN97
**/

class Solution {
public:

    /**
    Idea : store the frequency of all elements. iterate over the freq array from maxm to minm and sum up the 
    counts ith times.
    suppose count of elements from minm to maxm are [a1, a2, a3, a4, ..., an]
    now sum up them with ith times mean sum of ai * i where minm < i <= maxm
    Time Complexity - O(N)
    Space Complexity - O(N)
    where N is the maxm - minm value
    **/

    int reductionOperations(vector<int>& nums) {
        int minm = INT_MAX;
        int maxm = INT_MIN;
        int freq[50001];
        memset(freq, 0, sizeof freq);
        int n = 0; // stores the no of distincts elements in the nums array
        for(int num : nums){
            if(freq[num] == 0) n++; // appearing first time so count it.
            freq[num]++;
            minm = min(minm, num);
            maxm = max(maxm, num);
        }

        int nOperations = 0;
        for(int i = maxm; i > minm; i--){
            if(freq[i] > 0){
                nOperations += (n - 1) * freq[i];
                n--;
            }
        }
        return nOperations;
    }
};