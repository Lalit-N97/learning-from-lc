/**
Easy - Count Largest Group
https://leetcode.com/problems/count-largest-group/
Author : LalitN97
**/

class Solution {
public:
    
    /**
    Logic : 
    get the sum of digits and store the count of those numbers whose sum of digits are same.
    Now see what is the maximum count of largest digitSum group
    Time Complexity - O(N * LogN)
    Space Complexity - O(1)
    **/
    
    int getDigitSum(int n){
        int sum = 0;
        while(n){
            sum += (n % 10);
            n /= 10;
        }
        return sum;
    }
    
    int countLargestGroup(int n) {
        int hash[37] = {0};
        memset(hash, 0, sizeof hash);
        int maxDigitSum = 0;
        for(int i = 1; i <= n; i++){
            int digitSum = getDigitSum(i);
            hash[digitSum]++;
            maxDigitSum = max(maxDigitSum, hash[digitSum]);
        }
        
        int count = 0;
        for(int i = 0; i < 37; i++){
            if(hash[i] == maxDigitSum) count++;
        }
        return count;
    }
};