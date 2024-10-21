// https://leetcode.com/problems/consecutive-characters/

class Solution {
public:
    
    /**
    
    Logic : skip the first character of the string and iterate over the string such that
    you will be able to compare cur and the immediate previous character of the string.
    If those two characters are equal then increase the count otherwise reset the count but before
    resetting the count track the macLen encountered until this point.
    Time Complexity - O(N), Space Complexity - O(1)
    where N is the length of the string.
    
    **/
    
    int maxPower(string s) {
        int maxLen = 0;
        int count = 1;
        for(int i = 1; i < s.size(); i++){
            if(s[i] != s[i - 1]){
                maxLen = max(maxLen, count);
                count = 1;
            }
            else count++;
        }
        
        maxLen = max(maxLen, count);
        
        return maxLen;
    }
};