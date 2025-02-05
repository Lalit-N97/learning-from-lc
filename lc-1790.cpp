/**
Easy - Check if One String Swap Can Make Strings Equal
https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal
Written By : LalitN97
**/

class Solution {
public:

    /**
    Idea : iterate over the strings (these have same length) and track first and second mismatch using 
    by keeping two pointers in the mimatches.
    Return false, if you found third mismatch or if the first mimatch (in s1) is not same as that of second 
    mismatch (in s2) then return also return false;
    **/

    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size();
        int nMismatches = 0;
        int firstMisIdx = -1;
        int secondMisIdx = -1;
        for(int i = 0; i < n; i++){
            if(s1[i] != s2[i]) nMismatches++;
            if(nMismatches == 1 && firstMisIdx == -1) firstMisIdx = i;
            if(nMismatches == 2 && secondMisIdx == -1) secondMisIdx = i;
            if(firstMisIdx != -1 && secondMisIdx != -1 && s1[firstMisIdx] != s2[secondMisIdx]) return false;
            if(firstMisIdx != -1 && secondMisIdx != -1 && s1[secondMisIdx] != s2[firstMisIdx]) return false;
            if(nMismatches > 2) return false;
        }
        if(nMismatches == 1) return false;
        return true;
    }
};