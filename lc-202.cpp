// https://leetcode.com/problems/happy-number/

class Solution {
public:
    
    int sumOfSquares(int n){
        int ans = 0;
        while(n){
            int digit = n%10;
            ans += (digit * digit);
            n /= 10;
        }
        return ans;
    }
    
    // Space Complexity - O(N), Time Complexity - ?
    // bool isHappy(int n) {
    //     unordered_map<int, bool> isPresent;
    //     while(n != 1){
    //         isPresent[n] = true;
    //         n = sumOfSquares(n);
    //         if(isPresent[n] == true) return false;
    //     }
    //     return true;
    // }
    
    bool isHappy(int n) {
        int slow = n;
        int fast = n;
        do{
            slow = sumOfSquares(slow);
            fast = sumOfSquares(fast);
            fast = sumOfSquares(fast);
            if(fast == 1) return true;
        }while(slow != fast);
        return false;
    }
};