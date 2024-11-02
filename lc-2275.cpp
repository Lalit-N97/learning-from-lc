// https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero/

class Solution {
public:
    
    /**
    
    Logic : 
    To have the largest combination of numbers with bitwise AND greater than 0. Atleast one bit of choosen collection of numbers should be all set or 1.
    In other words, we have to find the max no of set bits in some ith bit of every number.
    This can be figured out by iterating over each bit in every numbers in candidates array and check if the some ith bit of the number is set or not. Track this count for each ithBit and use this count, once all the ith bits of every number is being seen, to find the maximum among the ithBit sets.
    Time Complexity - O(N * m)
    Space Complexity - O(1)
    where N is the size of the array and m = 32 is the no of bits in every number
    though the current constraints for each number is 10^7 so m <= 24.
    
    **/
    
    bool isIthBitSet(int num, int i){
        return num & (1 << i);
    }
    
    int largestCombination(vector<int>& candidates) {
        int maxNoOfCandidates = 0;
        for(int bit = 0; bit < 31; bit++){
            int countSetBits = 0;
            for(int candidate : candidates){
                if(isIthBitSet(candidate, bit)) countSetBits++;
            }
            maxNoOfCandidates = max(maxNoOfCandidates, countSetBits);
        }
        return maxNoOfCandidates;
    }
};