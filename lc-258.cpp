// https://leetcode.com/problems/add-digits/

class Solution {
public:
    
    int sumOfDigits(int n){
        int sum = 0;
        while(n){
            sum += (n%10);
            n /= 10;
        }
        return sum;
    }
    
    // recursive 
    int addDigits(int num) {
        if((num/10) == 0) return num;
        return addDigits(sumOfDigits(num));
    }
};