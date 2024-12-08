/**
Easy - Determine if String Halves Are Alike
https://leetcode.com/problems/determine-if-string-halves-are-alike/
Author : LalitN97
**/

class Solution {
public:
    
    /**
    Idea : 
    Traverse the string using two pointers one from start and other from end and check if the first half
    contains same number of vowels as that of second half.
    Time Complexity - O(N)
    Space Complexity - O(1)
    **/
    
    bool isVowel(char ch){
        char vowel[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        for(char c : vowel){
            if(c == ch) return true;
        }
        return false;
    }
    
    bool halvesAreAlike(string s) {
        int n = s.size();
        int count = 0;
        for(int i = 0; i < n/2; i++){
            if(isVowel(s[i])) count++;
            if(isVowel(s[n - 1 - i])) count--;
        }
        return count == 0;
        
    }
};