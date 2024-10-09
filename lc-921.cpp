// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/

class Solution {
public:
    
    /** 
    Logic : A valid string is such that every char '(' should end up (match) with every ')' character
    We can use stack to track those characters which needs to be inserted to make the string valid
    Time Complexity - O(N) , Space Complexity - O(N)
    **/
    
    int minAddToMakeValid(string s) {
        stack<char> stk;
        int nOpeningBracesRequired = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ')') {
                if(!stk.empty()) stk.pop();
                else nOpeningBracesRequired++;
            }
            else stk.push(s[i]);
        }
        return stk.size() + nOpeningBracesRequired;
    }
};