/**
Easy - Check if All A's Appears Before All B's
https://leetcode.com/problems/check-if-all-as-appears-before-all-bs/description/
Written By : LalitN97
**/

class Solution {
public:

    /**
    Idea : while iterating over the string track if upto a point if you got any B character
    If you got an A character check if the B character on left boolean value is true or not.
    Time Complexity - O(N)
    Space Complexity - O(1)
    **/

    bool checkString(string s) {
        bool isBPresentInLeft = false;
        for(char c : s){
            if(c == 'b'){
                isBPresentInLeft = true;
            }
            else if (isBPresentInLeft) return false;
        }
        return true;
    }
};