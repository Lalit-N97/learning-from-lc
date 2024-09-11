// https://leetcode.com/problems/minimum-bit-flips-to-convert-number/

/**
Logic : By obervation on some test cases figured out that the no of different bits between the start and goal will be our answer.
1. Let's take xor of those 2 numbers start and goal
2. check how many set bits are there in the xor - will be our answer
Time Complexity - O(logN), Space Complexity - O(1)
where N -> the maxnimum of two input numbers (max(start, goal))
**/

class Solution {
public:
    
    int minBitFlips(int start, int goal) {
        int x = start ^ goal;
        int count = 0;
        while(x){
            count++;
            x = x & (x - 1);
        }
        return count;
    }
};