/**
Easy - Check if All Characters Have Equal Number of Occurrences
https://leetcode.com/problems/check-if-all-characters-have-equal-number-of-occurrences/
Author : LalitN97
**/

class Solution {
public:
    
    /**
    Idea : 
    use a freq array to store the freq of each character in s.
    iterate over the array to find if any element has different freq.
    Time Complexity - O(N)
    Space Complexity - O(M)
    where N is the input string length and M = 26 no of letter in lowecase English alphabet
    **/
    
    bool areOccurrencesEqual(string s) {
        int freq[26];
        memset(freq, 0, sizeof freq);
        int anyoneEleFreq = 0;
        for(char ch : s) {
            anyoneEleFreq = ++freq[ch - 'a'];
        }
        for(int ele : freq) {
            if(ele != 0 && ele != anyoneEleFreq) return false;
        }
        return true;
    }
};