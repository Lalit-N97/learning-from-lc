/**
Medium - Valid Parenthesis String
https://leetcode.com/problems/valid-parenthesis-string/description/
Written By : LalitN97
**/

class Solution {
public:

    /**
    Idea : Looking at some examples I see we can use two stacks - 
    1. one to track the indices of left parenthesis and 
    2. other to track the indices of stars
    On iterating the input string whenever we'll find a left parenthesis keep its index in the parenthesis stack
    and when we'll find a star keep its index in the starStk (this is used when left parenthesis are exhuasted 
    for the current right parenthesis, also star can be used as a right parenthesis if all the right parenthesis
    are exhausted and still left parenthesis are remaining in the parenthesisStk)
    Time Complexity - O(N)
    Space Complexity - O(N)
    where N is the size of the input string
    **/

    bool checkValidString(string s) {
        stack<int> parenthesisStk;
        stack<int> starsStk;
        int n = s.size();
        for(int i = 0; i < n; i++){
           char ch = s[i];
           if(ch == '*') starsStk.push(i);
           else if(ch == '(') parenthesisStk.push(i);
           else{
            if(parenthesisStk.empty() && starsStk.empty()) return false;
            else if(!parenthesisStk.empty()) parenthesisStk.pop();
            else starsStk.pop();
           }
        }
        while(!parenthesisStk.empty() && !starsStk.empty()){
            if(parenthesisStk.top() > starsStk.top()) return false;
            else {
                starsStk.pop();
                parenthesisStk.pop();
            }
        }
        return parenthesisStk.empty();
    }
};