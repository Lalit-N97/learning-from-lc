/**
Medium - Minimum Operations to Exceed Threshold Value II
https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-ii
Written By : LalitN97
**/

class Solution {
public:

    /**
    Idea : keep all the input numbers in minimum priority queue (N*LogN operation). Once all the elements are
    kept in the priority queue, pop two minimu elements from priority queue and insert a new element after
    applying the operation. 
    Time Complexity - O(N * LogN + M * LogN)
    Space Complexity - O(N)
    where N is the size of the input array
    and M is the resultant no of operations we are going to make.
    **/

    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> minPQ;
        for(long long num : nums) minPQ.push(num);
        int nOperations = 0;
        while(minPQ.size() > 1 && minPQ.top() < k){
            long long firstMin = minPQ.top(); minPQ.pop();
            long long secondMin = minPQ.top(); minPQ.pop();
            minPQ.push(firstMin * 2 + secondMin);
            nOperations++;
        }
        return nOperations;
    }
};