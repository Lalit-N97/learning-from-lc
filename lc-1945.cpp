// https://leetcode.com/problems/sum-of-digits-of-string-after-convert/

class Solution {
public:
    
    /**
     Followed the algorithm mentioned in the problem statement
     Time Complexity - O(k*N) where k is at max 4, Space Complexity - O(1)
    **/

    int getSum(int ch){
        int sum = 0;
        while(ch){
            sum += (ch)%10;
            ch /= 10;
        }
        return sum;
    }
    
    int getLucky(string s, int k) {
        int sumOfDigits = 0;
        for(char ch : s){
            sumOfDigits += getSum((ch - 'a') + 1); // Transformation#1
        }
        int i = 1;
        // based on the contraints the single digit sum can be obtained within 4 transformations, so not further calculating the sumOf Digits
        while(i <= 3 && i < k){
            sumOfDigits = getSum(sumOfDigits); // rest k - 1 transformations happen here.
            i++;
        }
        return sumOfDigits;
    }
};