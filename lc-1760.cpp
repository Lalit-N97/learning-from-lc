/**
Medium - Minimum Limit of Balls in a Bag
https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/
Author : LalitN97
**/

class Solution {
public:
    
    /**
    Intuition : 
    You need to practive some binary search problems like SPOJ PRATA/ book allocation/ aggresive cows
    where we need to maximize the minimum of something or minimize the maximum of something
    Here we need to minimize the penalty(maximum no of balls inside one of the bags)
    So we are going to set this maximum no of balls to some value. e.g.
    try to find the number of operations (let's say x) required to get maximum no of balls as y = 4 
    among the bags.
    if we are allowed to do the x operations as per the maxOperations arguments then we should consider
    minimizing y. Now y = 3 (i.e. try to get the no of operations required to slit bags such that max
    number of balls in the bags become 3) and see let's say the no of operation you get are z. Those z operations
    are allowed as per maxOperations (where z <= maxOperations). So reach at a point to minimize y such that
    the numeber of operations you get is greater than allowed maxOperations. then previous no of max balls is
    our answer.
    Time Complexity - O(N*LogN)
    Space Complexity - O(1)
    **/
    
    int getnOperations(vector<int>& nums, int maxnBalls){
        int nOperations = 0;
        for(int num : nums){
            if(num > maxnBalls){
                // find the min number of operations required to get to maxnBalls from cur num
                // do -1 from the result when num is a multiple of maxnBalls
                nOperations += (num/maxnBalls - (num%maxnBalls == 0 ? 1 : 0));
            }
        }
        return nOperations;
    }
    
    int minimumSize(vector<int>& nums, int maxOperations) {
        /** search range is min balls to max balls among bags i.e. 1 to max(nums[i]) **/
        int start = 1;
        int end = 0;
        int minnBalls = 1;
        for(int num : nums) end = max(end, num);
        while(start <= end){
            int mid = start + (end - start)/2;
            int nOperations = getnOperations(nums, mid);
            if(nOperations <= maxOperations){ // whether the cur min number of balls makes it possible to get from required number of maxOperations.
                minnBalls = mid;
                end = mid - 1;
            }
            else start = mid + 1;
        }
        return minnBalls;
    }
};