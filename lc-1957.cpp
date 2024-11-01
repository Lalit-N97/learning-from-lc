// https://leetcode.com/problems/delete-characters-to-make-fancy-string/

class Solution {
public:
    
    /**
    Logic : 
    Keep a resultant string to be built and iterate over the string and add the characters into the resultant string except the character whenever you see more than 3 same consecutive characters.
    Time Complexity - O(N)
    Space Complexity - O(N)
    where N is the size of the input string
    **/
    
    string makeFancyString(string s) {
        string fancyString = "";
        fancyString += s[0];
        int count = 1;
        for(int i = 1; i < s.size(); i++){
            int curChar = s[i];
            int prevChar = s[i - 1];
            if(curChar == prevChar) count++;
            else count = 1;
            if(count < 3) fancyString += curChar;
        }
        return fancyString;
    }
};