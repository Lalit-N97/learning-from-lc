/**
Medium - Count Vowel Strings in Ranges
https://leetcode.com/problems/count-vowel-strings-in-ranges/description/
Written By : LalitN97
**/

class Solution {
public:

    /**
    Idea : iterate over the input array and form a prefixSum array where each element of it will store
    no of strings from 0 to ith index are starting and ending with vowels.
    Once the prefixSum array formed, use this to answer input queries in contant time

    To check if a input character is vowel or not use bitmasking. Take a mask of 26 bits with set bits at 
    vowels places and make a number from input string with bit set at the one of the 26 characters and bitwise and 
    this number with the mask to see if the result is greater than 0 (which means it is a vowel) otherwise
    not a vowel.
    Time Complexity - O(N + Q)
    Space Complexity - O(N)
    **/

    int vowelMask = 0;

    void formVowelMask(){
        char vowels[] = {'a', 'e', 'i', 'o', 'u'};
        for(char vowel : vowels) vowelMask |= 1 << (vowel - 'a');
    }

    bool isVowel(char ch){
        int vowelBit = 1 << (ch - 'a');
        return vowelBit & vowelMask;
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        formVowelMask();
        int n = words.size();
        vector<int> prefixSum(n + 1, 0);
        for(int i = 0; i < n; i++){
            string word = words[i];
            prefixSum[i + 1] = prefixSum[i] + (isVowel(word[0]) && isVowel(word[word.size() - 1]));
        }

        int q = queries.size();
        vector<int> count(q, 0);
        for(int i = 0; i < q; i++){
            int leftIdx = queries[i][0];
            int rightIdx = queries[i][1];
            count[i] = prefixSum[rightIdx + 1] - prefixSum[leftIdx];
        }
        return count;
    }
};