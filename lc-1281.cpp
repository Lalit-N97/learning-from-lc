// https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/

class Solution {
public:
    
    /**
    Logic : iterate over the number's digits and calculate their product and sum 
    return the difference then between them.
    Time Complexity - O(log(N)), Space Complexity - O(1)
    where N is the input number.
    
    **/
    
    int subtractProductAndSum(int n) {
        int product = 1;
        int sum = 0;
        while(n){
            int digit = n%10;
            product *= digit;
            sum += digit;
            n = n/10;
        }
        return product - sum;
    }
};