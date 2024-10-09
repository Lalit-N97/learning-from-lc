// https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/

class Solution {
public:
    
    /**
    Logic : Since there are equal number of both types of characters (']' and '['). Now After removing
    the balanced part from the string (using stack) we are left with unbalanced string part which can get balanced
    by swaping two chars that makes 2 sets of unbalanced paranthesis balanced. hence ans/2 + 1;
    Time Complexity - O(N), Space Complexity - O(N)
    Can be done without using stack.
    Time Complexity - O(N), Space Complexity - O(1)
    **/
    
    int minSwaps(string s) {
        // stack<char> stk;
        // int nInvalidCharConfiguration = 0;
        // for(int i = 0; i < s.size(); i++){
        //     if(s[i] == ']'){
        //         if(stk.empty()) nInvalidCharConfiguration++;
        //         else stk.pop();
        //     }
        //     else stk.push(s[i]);
        // }
        // return ceil((double)nInvalidCharConfiguration/2);
        
        // without stack
        int stackSize = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ']') {
                if(stackSize > 0) stackSize--;
            }
            else stackSize++;
        }
        return ceil((double)stackSize/2);
    }
};