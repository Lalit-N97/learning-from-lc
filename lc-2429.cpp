/**
Medium - Minimize XOR
https://leetcode.com/problems/minimize-xor/description/
Written By : LalitN97
**/

class Solution {
public:

    /**
    Idea : count the no of set bits in num1 and num2 say them n1 and n2 repectively
    if n1 <= n2 then our answer is 0
    else take the first (n1 - n2) set bits from num1's LSB (Least Significant Bit) to MSB
    Time Complexity - O(log(N))
    Space Complexity - O(1)
    **/

    int getSetBitsCount(int num){
        int nSetBits = 0;
        while(num) {
            nSetBits++;
            num = num & (num - 1);
        }
        return nSetBits;
    }

    int minimizeXor(int num1, int num2) {
        int nSetBits1 = getSetBitsCount(num1);
        int nSetBits2 = getSetBitsCount(num2);
        int diff = nSetBits1 - nSetBits2;
        if(diff == 0) return num1;
        if(diff > 0){
            int x = 0;
            int mask = 1;
            while(diff){
                if(mask & num1){
                    x |= mask;
                    diff--;
                }
                mask <<= 1;
            }
            return x ^ num1;
        }
        int ans = 0;
        int bitmask = 1;
        diff = abs(diff);
        while(diff){
            if(!(num1 & bitmask)){
                diff--;
            }
            ans |= bitmask;
            bitmask <<= 1;
        }
        int remNum = num1 ^ ans;
        return ans | remNum;
    }
};