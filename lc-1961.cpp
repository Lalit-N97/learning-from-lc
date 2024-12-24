/**
Easy - Check If String Is a Prefix of Array
https://leetcode.com/problems/check-if-string-is-a-prefix-of-array/
Written By : LalitN97
**/

class Solution {
public:
    
    /**
    Idea : 
    iterate over the words input array from left. Find if the each word from the array staring from left
    concatenates to form the string s using a pointer which tracks the characters in the string s.
    Time Complexity - O(N)
    Space Complexity - O(1)
    where N is the size of input string s
    **/
    
    bool isPrefixString(string s, vector<string>& words) {
        int n = s.size();
        int i = 0;
        for(string word : words){
            int j = 0;
            int m = word.size();
            while(i < n && j < m && s[i] == word[j]){
                i++;
                j++;
            }
            if(i == n && j == m) return true;
            if(j < m) return false;
        }
        return false;
    }
};