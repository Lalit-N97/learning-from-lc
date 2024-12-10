/**
Easy - Largest Odd Number in String
https://leetcode.com/problems/largest-odd-number-in-string/
Author : LalitN97
**/

class Solution {
public:
    
    /**
    Idea : traverse the string from backwards and stop at a point if you got first odd number
    create a new string from 0 to that odd number or use substring method of the programming language
    Time Complexity - O(N)
    Space Complexity - O(N)
    where N is the length of input string
    **/
    
    string largestOddNumber(string num) {
        int i = num.size() - 1;
        while(i >= 0 && !((num[i] - '0') & 1)) i--;
        return i < 0 ? "" : num.substr(0, i + 1);
    }
};