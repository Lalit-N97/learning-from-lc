/**
Medium - Unique Length-3 Palindromic Subsequences
https://leetcode.com/problems/unique-length-3-palindromic-subsequences/description/
Written By : LalitN97
**/

class Solution {
public:

    /**
    Idea :
    so we have 26 lowercase english letters. I am going to store first and last index of every letter present
    in the input string. Once the index storing part is done, for each lowercase letter we can iterate over the
    string to find unique no of characters in between first and last index of that particular character.
    Time Complexity - O(N * 26)
    Space Complexity - O(N)
    where N is the size of the input string
    **/

    int countPalindromicSubsequence(string s) {
        int leftIdx[26];
        memset(leftIdx, -1, sizeof leftIdx);
        int rightIdx[26];
        memset(rightIdx, -1, sizeof rightIdx);
        int n = s.size();
        for(int i = 0; i < n; i++) {
            int ch = s[i] - 'a';
            rightIdx[ch] = i;
            if(leftIdx[ch] == -1) leftIdx[ch] = i;
        }

        int nValid3PalindromicSubsequences = 0;
        for(int i = 0; i < 26; i++){
            if(leftIdx[i] != rightIdx[i]){
                int bitMask = 0;
                for(int j = leftIdx[i] + 1; j < rightIdx[i]; j++){
                    int lowercaseLetterMask = 1 << (s[j] - 'a');
                    if(!(bitMask & lowercaseLetterMask)) nValid3PalindromicSubsequences++;
                    bitMask |= lowercaseLetterMask;
                }
            }
        }
        return nValid3PalindromicSubsequences;
    }
};