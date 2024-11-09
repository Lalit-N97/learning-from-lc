// Medium - Minimum Array End
// https://leetcode.com/problems/minimum-array-end/

class Solution {
public:
    
    /**
    Logic: 
    To have a number whose bitwise AND with input x is always x then, to find those numbers we can onyl tweak those bits in input number x whose where bit is 0. Tweking them such that it forms a increasing sequence with every change(tweaking) and get us the smallest number with n - 1 changes.
    It could be solved by ORing the bitwise number formed from (n - 1) number with the original number x, with every bit of (n - 1) number from end ORed with every 0th bit of original x number from end.
    Time Complexity - O(Log2(N))
    Space Complexity - O(1)
    where N is the input number max(x, n);
    
    **/
    
    long long minEnd(int n, int x) {
        long long ans = x;
        int temp = n - 1;
        long long i = 0; // to iterate over the bits of the input number x
        while(temp){
            long long digit = (temp & 1);
            long long bitMask = ((long long)1 << i); 
            // to calculate current bit is set or not
            if((ans & bitMask) == 0){
                ans |= (digit << i);
                temp = (temp >> 1);
            }
            i++;
        }
        return ans;
    }
};