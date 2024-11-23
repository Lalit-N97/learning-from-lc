/**
Easy - Truncate Sentence
https://leetcode.com/problems/truncate-sentence/
Author : LalitN97
**/

class Solution {
public:
    
    /**
    Logic : 
    Iterate over the string and insert every character into the resultant string. While doing this keep track of spaces. If you found the space reduce the k by 1 and whenever the k becomes 0 you should return the resultant string.
    Time Complexity - O(N)
    Space Complexity - O(1)
    where N is the size of the input string
    **/
    
    string truncateSentence(string s, int k) {
        string ans = "";
        for(char ch : s){
            if(ch == ' ') k--;
            if(k == 0) break;
            ans += ch;
        }
        return ans;
    }
};