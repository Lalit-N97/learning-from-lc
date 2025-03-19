/**
Medium - Minimum Operations to Make Binary Array Elements Equal to One I
https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i
Written By : LalitN97
**/

class Solution {
public:

    /**
    Idea : oberserving few examples will direct us to greedy approach, where whenever we see a 0 flip it with the next 
    2 elements as well, while iterating over the array. If in the last two indices of the array has any zero in it
    then all elements can't be made 1. Count the valid operations as well.
    Time Complexity - O(3*N)
    Space Complexity - O(1)
    where N is the size of input array.

Question - How can we prove that the solution we are getting from this approach is minimum?

Answer -
The key insight is that the problem has optimal substructure. This means that the optimal solution for the entire array includes optimal solutions for its subarrays.

Suppose there was a better solution that didn't flip immediately upon seeing a 0. This would mean:

We skip flipping at position i (where nums[i] = 0).
We flip at some later position j (where j > i).
But this can't be better because:

We still need to make the same number of flips (or more).
We might run out of array length, making the problem unsolvable.
Therefore, the greedy choice of flipping immediately is always optimal.

    **/

    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int minOperations = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0 && i > n - 3) return -1;
            if(nums[i] == 0){
                nums[i] ^= 1;
                nums[i + 1] ^= 1;
                nums[i + 2] ^= 1;
                minOperations++;
            }
        }
        return minOperations;
    }
};