/**
Easy - Check If a Word Occurs As a Prefix of Any Word in a Sentence
https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/
Author : LalitN97
**/

class Solution {
public:
    
    /**
    Idea is to take two pointers one will track the sentence and other will track the searchWord.
    iterate over the string sentence and for each char in sentence appears at the start or after the space
    check whether the substring is a searchWord or not using simulation
    Time Complexity - O(N)
    Space Complexity - O(1)
    where N is the input string length
    **/
    
    int isPrefixOfWord(string sentence, string searchWord) {
        int i = 0, j = 0;
        int n = sentence.size();
        int m = searchWord.size();
        bool found = false;
        int wordCount = 1;
        
        while(i < n){
            if(found) return wordCount;
            while(i < n && j < m && sentence[i] == searchWord[j]){
                i++;
                j++;
            }
            if(j == m) found = true;
            else {
                j = 0;
                while(i < n && sentence[i] != ' ') i++;
                wordCount++;
                i++;
            }
        }
        
        return found ? wordCount : -1;
    }
};