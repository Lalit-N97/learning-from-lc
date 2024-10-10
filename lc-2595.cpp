// https://leetcode.com/problems/number-of-even-and-odd-bits/

class Solution {
public:
    
    // Time Complexity - O(LogN), Space Complexity - O(1)
    
    vector<int> evenOddBit(int n) {
        vector<int> ans(2, 0);
        bool isOddBit = false;
        while(n){
            if(isOddBit){
                ans[1] += (n & 1);
            }
            else{
                ans[0] += (n & 1);
            }
            isOddBit = !isOddBit;
            n >>= 1;
        }
        return ans;
    }
};