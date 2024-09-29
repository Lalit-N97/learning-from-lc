// https://leetcode.com/problems/binary-gap/

/**
 Logic : iterate over the binary form of the input number and track the distance between
 two adjacent 1's. Take the max distance among them while tracking.
 Time Complexity - O(log(N)),  Space Complexity - O(1)
**/

class Solution {
public:
    int binaryGap(int n) {
        int idx = 0;
        int prev = -1;
        int maxDist = 0;
        while(n){
            int d = n & 1;
            if(d == 1){
                if(prev != -1){
                    maxDist = max(maxDist, idx - prev);
                }
                prev = idx; 
            }
            idx++;
            n = n >> 1;
        }
        return maxDist;
    }
};