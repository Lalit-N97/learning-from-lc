/**
Medium - Minimum Operations to Make Array Equal
https://leetcode.com/problems/minimum-operations-to-make-array-equal/description/
Written By : LalitN97
**/

class Solution {
public:

    /**
    Idea : through observation from n = 1 to n = 8 examples we found the min operations required to make all
    elements of an array equal is to find the middle value of the elements of array and take sum of the 
    difference of each elements from that middle element.
    Whether n is odd or even, the middle element will be (2*(n-1))/2 + 1;
    Our minimum operation can be found by some more observations that 
    in case of odd n, the minimum operations are equal to sum of first t = n/2 even natural numbers
    in case of even n, the min operations are equal to sum of first t = n/2 odd natural numbers.
    Also, sum of first t even natural numbers are given by t * (t - 1)
    and sum of first t odd natural number are given by t * (t);
    Time Complexity - O(1)
    Space Complexity - O(1)
    **/

    int minOperations(int n) {
        int midIdx = n/2;
        if(n & 1){
            return midIdx * (midIdx + 1);
        }
        else return midIdx * (midIdx);
    }
};