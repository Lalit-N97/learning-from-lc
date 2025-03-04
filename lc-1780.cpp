/**
Medium - Check if Number is a Sum of Powers of Three
https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three
Written By : LalitN97
**/

class Solution {
public:

    /**
    Idea : N = 3^x + 3^y + ... so on
    where x and y and other powers are distinct and upto 14 as per the constraints.
    e.g : 21 = 3 * 7
    =>    21 = 3 * (1 + 6)
    =>    21 = 3 * (1 + 3 * 2)
    Since this 21 after repeatedly dividing by 3 gives us 2 at the end and 2 can't be further divisible by 3 
    hence return false in this case.
    e.g : 91 = 1 + 90
    =>    91 = 1 + (3 * 10)
    =>    91 = 1 + (3 * (1 + 9))
    =>    91 = 1 + (3 * (1 + 3 * 3)) Since at the end the number becomes 3 after repeatedly reduce the number
    by either decrementing by 1 or dividing by 3, hence return true in this case.
    Algo : divide the input number by 3 until you reduce the input number to 1. During division
    if you are able to divide the number by 3 then divide it by 3, ohtherwise subtract one from the number 
    and check if it is divisible by 3, if after decrementing the number by 1 and the division with 3 is not
    possible then return false, otherwise keep dividing the number by 3.
    Time Complexity - O(log3(N))
    Space Complexity - O(1)
    where N is the input number
    **/

    bool checkPowersOfThree(int n) {
        while(n >= 3){
            if(n % 3 == 0){
                n /= 3;
            }
            else if((n - 1) % 3 == 0){
                n = (n - 1) / 3;
            }
            else return false;
        }
        return n == 1;
    }
};