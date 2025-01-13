/**
Medium - Minimum Length of String After Operations
https://leetcode.com/problems/minimum-length-of-string-after-operations/description/
Written By : LalitN97
**/

class Solution {
public:

    /**
    Idea : choosing index i and removing its left closest and right closed same element will always ends up
    making odd no of elements to 1 and even no of elements to 2.
    Using this approach we counted the occurences of all characters in the input string and then iterate over
    the occurences array and checked if any charater occurence is odd times then add 1 to minLength otherise
    add 2 to minLength
    Time Complexity - O(N + K)
    Space Complexity - O(K)
    where N is the size of input string 
    and K is the size of characters array
    **/

    int minimumLength(string s) {
        int charCount[26];
        memset(charCount, 0, sizeof charCount);
        int minSize = 0;
        for(char c : s) {
            charCount[c - 'a']++;
            if(charCount[c - 'a'] == 1) minSize += 1; // for the first time add 1 to the minLength
            else{ // otherise count is greater than 1, in that case when you see even character count
            // then add 1 to minLength and if you see odd char count then subtract 1 from the minLength.
            // This logic can be observed on looking at few examples.
                if(charCount[c - 'a'] & 1) minSize--;
                else minSize++;
            }
        }

        /** instead of checking the frequency array in different loop, we can compensate the freq check in the same
        loop where we are build the frequency array in the above loop.
        for(int count : charCount){
            if(count > 0){
                if(count & 1) minSize += 1;
                else minSize += 2;
            }
        }
        **/
        return minSize;
    }
};