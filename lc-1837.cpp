/**
Easy - Sum of Digits in Base K
https://leetcode.com/problems/sum-of-digits-in-base-k/
Written By : LalitN97
**/

class Solution {
public:
    
    /**
    Idea : just like we fetch each digit for base 10 using 
    while (n){
    int d = n%10;
    n /= 10;
    }
    we can fetch each digit for base k exactly like above but replace base 10 with base k
    As every 10 base number can be expanded like -> 345 = 3 * 100 + 4 * 10 + 5 * 1
    Similarly k base number can be expanded like -> 345 = (345/6^2)%6 * (6^2) + (345/6^1)%6 * (6^1) + (345/6^0)%6 * (6^0)
    Time Complexity - O(logK(N)) -> log of N with base K
    Space Complexity - O(1)
    **/
    
    int sumBase(int n, int k) {
        int digitSum = 0;
        while(n){
            digitSum += n%k;
            n /= k;
        }
        return digitSum;
    }
};