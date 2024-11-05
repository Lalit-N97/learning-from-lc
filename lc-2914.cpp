// Medium - Minimum Number of Changes to Make Binary String Beautiful

// https://leetcode.com/problems/minimum-number-of-changes-to-make-binary-string-beautiful/

class Solution {
public:
    
    /**
    
    Logic : 
    Iterate over the string from 1st index and look for consecutive same digits by checking current and previous character. 
    In case you found the same character as that of previous, we'll track this by incrementing the nSameDigits by 1.
    In case you found a different character as that of previous, we'll change the previous digit to make it as same current digit (not actually changing) but by modifying nSameDigit variable.
    Time Complexity - O(N)
    Space Complexity - O(1)
    where N is the size of the input string
    
    **/
    
    int minChanges(string s) {
        int n = s.size();
        int nChangeDigit = 0;
        int nSameDigit = 1;
        for(int i = 1; i < n; i++){
            if(s[i] == s[i - 1]){
                nSameDigit++;
            }
            else{
                // odd no of same consecutive digits
                if(nSameDigit & 1){
                    nChangeDigit++;
                    nSameDigit = 2;
                }
                // even no of same consecutive digits
                else nSameDigit = 1;
            }
        }
        return nChangeDigit;
    }
};