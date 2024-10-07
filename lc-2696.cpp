// https://leetcode.com/problems/minimum-string-length-after-removing-substrings/

class Solution {
public:
    
    /**
    Logic : Brute Force approach, iterate over the string multiple times. In every iteration remove AB or CD string
    and again do the same operation on new string.
    Time Complexity - O(N^2), Space Complexity - O(N^2)
    **/
    
    // string removeSubstring(string s){
    //     string ans = "";
    //     int n = s.size();
    //     int i = 0;
    //     for(; i < n - 1; i++){
    //         if(s[i] == 'A' && s[i + 1] == 'B'){
    //             i++;
    //         }
    //         else if(s[i] == 'C' && s[i + 1] == 'D'){
    //             i++;
    //         }
    //         else{
    //             ans += s[i];
    //         }
    //     }
    //     if(i == n - 1) ans += s[i];
    //     return ans;
    // }
    
    int minLength(string s) {
        // int prevLen = -1;
        // int curLen = s.size();
        // while(prevLen != curLen){
        //     string smaller = removeSubstring(s);
        //     s = smaller;
        //     prevLen = curLen;
        //     curLen = s.size();
        // }
        // return curLen;
        
        /**
        
        Logic : Take a stack (LIFO) data structure. Iterate over the string and keep every element into the stack
        See if the you get a 'B' while iterating over the string, check if corresponding 'A' is present at the top of the stack - if yes then pop the stack similary in case of 'CD'. 
        Time Complexity - O(N), Space Complexity - O(N)
        
        **/
            
        
        stack<char> stk;
        int i = 0;
        int n = s.size();
        while(i < n){
            if((s[i] == 'B' && !stk.empty() && stk.top() == 'A') || (s[i] == 'D' && !stk.empty() && stk.top() == 'C')){
                stk.pop();
            }
            else stk.push(s[i]);
            i++;
        }
        return stk.size();
    }
};