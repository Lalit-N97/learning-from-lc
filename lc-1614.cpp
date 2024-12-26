/**
Easy - Maximum Nesting Depth of the Parentheses
https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/
Written By : LalitN97
**/

class Solution {
public:
    
    /**
    Idea : iterate over the string and increase the depth by 1 of nested paranthesis if you encounter '('
    and decrease the depth by 1 if encounter ')'.
    This works only in case of balanced or valid paranthesis orientation.
    Time Complexity - O(N)
    Space Complexity - O(1)
    **/
    
    int maxDepth(string s) {
        int nestedDepth = 0;
        int maxNestedDepth = 0;
        for(char c : s){
            if(c == '(') maxNestedDepth = max(maxNestedDepth, ++nestedDepth);
            else if(c == ')') nestedDepth--;
        }
        return maxNestedDepth;
    }
};