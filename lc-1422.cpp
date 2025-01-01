/**
Easy - Maximum Score After Splitting a String
https://leetcode.com/problems/maximum-score-after-splitting-a-string/description/
Written By : LalitN97
**/

class Solution {
public:

    /**
    Idea : 
    Two pass solution : 
    iterate over the string and count the total no of ones in the string.
    Again iterate over the string from left to right and at each point track the no of zeros and ones encountered.
    these become leftZeros and rightOnes = (totalOnes - leftOnes).
    answer will be max(leftZeros + rightOnes, prevMax);

    One pass solution : (from discussion)
    while iterating from left to right at each point we are checking the maximum value of
    max(leftZeros + rightOnes) => max(leftZeros + (totalOnes - leftOnes)) 
    => max(leftZeros - leftOnes + totalOnes).
    Since at each point of string totalOnes are constant so move the totalOnes out of max function
    => max(leftZeros - leftOnes) + totalOnes
    All these can be found in one iteration from left to right
    Time Complexity - O(N)
    Space Complexity - O(1)
    
    **/

    int maxScore(string s) {
        int leftOnes = 0;
        int leftZeros = 0;
        int ans = INT_MIN;
        // at the end of iteration of string leftOnes and leftZeros becomes totalOnes and totalZeros respectively.
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '0') leftZeros++;
            else leftOnes++;
            if(i != s.size() - 1) ans = max(ans, leftZeros - leftOnes);
        }
        return ans + leftOnes;
    }
};