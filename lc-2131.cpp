/**
Medium - Longest Palindrome by Concatenating Two Letter Words
https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words
Written By : LalitN97
**/

class Solution {
public:

    /**
    Idea : lets count every word using a hashmap or 2D array of 25*25 size. 
    CASE I : If the word has both different characters then 
    we'll add the minimum count of this word and the count of its mirror word. e.g. if word is 'ab' then mirror word is 'ba'.
    CASE II : if the word is composed of same characters and the count of that word is even then add the count in the answer.
    CASE III : if the word has same characters and the count of those words are odd, then add the count - 1 in the answer, but
    track the odd count using a flag, so that we can add 1 in the answer at the very end of our code. This makes sure the one
    of the odd count word appears at the middle of the palindrome.
    Time Complexity - O(N * len(word))
    Space Complexity - O(C)
    where C = 26 * 26 to store the characters in the 2D array representing a 2character word.
    **/

    int longestPalindrome(vector<string>& words) {
        int freq[26][26];
        memset(freq, 0, sizeof freq);
        int n = words.size();
        for(string word : words){
            int first = word[0] - 'a';
            int second = word[1] - 'a';
            freq[first][second]++;
        }

        int maxLen = 0;
        bool oddCountFlag = false;
        for(int i = 0; i < 26; i++){
            for(int j = i; j < 26; j++){
                if(i != j){
                    // different characters
                    maxLen += 4 * min(freq[i][j], freq[j][i]);
                }
                else{
                    if(freq[i][j] & 1) oddCountFlag = true;
                    maxLen += 2 * (freq[i][j] - (freq[i][j]%2));
                }
            }
            cout << "\n";
        }
        return maxLen + 2 * oddCountFlag;
    }
};