/**
Medium - Number of Substrings Containing All Three Characters
https://leetcode.com/problems/maximum-candies-allocated-to-k-children
Written By : LalitN97
**/

class Solution {
public:

    /**
    Idea : splitting the candies equally among k children can be interpretted as trying to assign m candies to k 
    children, if we are able to allocating m candies to k children equally then try allocating m + 1 candies to k children
    and try to maximise m allocation value.
    It seems we need to iterate over the candies array for each m which leads to N*M time but allocating m candies to 
    k children in binary search manner will significantly reduce the time complexity. Our search space for m will be
    from 1 to max of (candies array element). inclusive.
    Time Complexity - O(N * LogM)
    Space Complexity - O(1)
    where N is the size of input array (candies)
    and M is the max element in candies array.
    **/

    bool isAllocationPossible(vector<int>& candies, long long k, int m){
        long long nMEqualCandies = 0;
        for(int pile : candies){
            nMEqualCandies += (pile / m);
        }
        return nMEqualCandies >= k;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        int start = 1;
        int end = 1;
        for(int pile : candies) end = max(end, pile);
        int maxAllocatedCandies = 0;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(isAllocationPossible(candies, k, mid)){
                maxAllocatedCandies = mid;
                start = mid + 1;
            }
            else end = mid - 1;
        }
        return maxAllocatedCandies;
    }
};