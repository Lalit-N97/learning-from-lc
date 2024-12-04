/**
Medium - Make String a Subsequence Using Cyclic Increments
https://leetcode.com/problems/make-string-a-subsequence-using-cyclic-increments/
Author : LalitN97
**/

class Solution {
public:
    
    /**
    Idea : just go through one test case to figure out the solution.
    We need to iterate over both the strings using two different pointers comparing each of the characters
    of them one by one. If the current charecters statisfies the condition as per the operation (mentioned)
    in the question, then increment both the pointers to compare their next character. Else only
    increment the pointer of str1 string
    Time Complexity - O(N + M)
    Space Complexity - O(1)
    where N is the size of the input string str1 and M is the size of input string str2
    **/
    
    bool canMakeSubsequence(string str1, string str2) {
        int i = 0;
        int j = 0;
        int n = str1.size();
        int m = str2.size();
        while(i < n && j < m){
            if((str1[i] == str2[j]) ||
              (str2[j] == ((((str1[i] - 'a') + 1) % 26) + 'a'))){
                i++;
                j++;
            }
            else i++;
        }
        return j == m;
    }
};