/**
Medium - Construct K Palindrome Strings
https://leetcode.com/problems/construct-k-palindrome-strings/description/
Written By : LalitN97
**/


class Solution {
public:

    /**
    Idea : Looking at the test cases help me realize a approach which is Greedy in nature.
    We see that if input K is greater than size of the input string there there wouldn't be any such palindrome
    combination possible, also all possible palindrome combinations lies below the size of the input string and 
    greater than some minimum no of palindromes formed (try checking some exaples to get it realized).
    We have to find the minimum no of K palindrome formed using all the characters of the input string.
    Time Complexity - O(N)
    Space Complexity - O(m)
    where N is the size of the string
    and m is the no of distinct characters in the input string
    **/

    bool canConstruct(string s, int k) {
        int n = s.size();
        int nOddOccurences = 0; // the no of odd occurences of the distinct characters in the string gives us
        // the minimum no of palindromes formed using all the characters of the input string
        bool isCharOdd[26] = {0};
        memset(isCharOdd, false, sizeof isCharOdd);
        for(char ch : s){
            isCharOdd[ch - 'a'] = (!isCharOdd[ch - 'a']); // whenever you see even char freq flip it to odd freq and vice versa
            if(isCharOdd[ch - 'a'] & 1) nOddOccurences++; // at every odd character frequency increment no of odd occurences and at every even character frequency decrement the no of odd character occurences.
            else nOddOccurences--;
        }
        if(k <= s.size() && k >= nOddOccurences) return true;
        else return false;
    }
};