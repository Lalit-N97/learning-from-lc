/**
Medium - The kth Factor of n
https://leetcode.com/problems/the-kth-factor-of-n
Written By : LalitN97
**/

class Solution {
public:

    /**
    Idea : from i = 1 to n, check if i is the factor of n or not. Time will be linear.
    Otherwise, we can check from i = 1 to sqrt(n), to see if i is the factor of n or not.
    Time Complexity - O(sqrt(N) + K)
    Space Complexity - O(1)
    **/

    int kthFactor(int n, int k) {
        int kFactor = -1;
        int mid = sqrt(n);
        for(int i = 1; i <= mid; i++){
            int firstFactor = i;
            int secondFactor = n/i;
            if(n%firstFactor == 0) k--;
            if(k == 0) return firstFactor;
        }
        for(int i = mid; i >= 1; i--){
            int firstFactor = i;
            int secondFactor = n/i;
            if(firstFactor != secondFactor && n%secondFactor == 0) k--;
            if(k == 0) return secondFactor;
        }
        return -1;
    }
};