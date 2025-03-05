/**
Medium - Count Total Number of Colored Cells
https://leetcode.com/problems/count-total-number-of-colored-cells
Written By : LalitN97
**/

class Solution {

    /**
    Idea : on observing the no of colored boxes increasing pattern on increasing the time, we got
    for the first minute, at t = 1, colored = 1;
    at t = 2, colored = 1 + 1*4
    at t = 3, colored = 1 + 1*4 + 2*4;
    at t = 4, colored = 1 + 1*4 + 2*4 + 3*4;
    at t = n, colored = 1 + 1*4 + 2*4 + ... + (n - 1)*4
    hence at t = n, simplified sum is 1 + 4 * (n * (n - 1))/2 => 1 + 2 * n * (n - 1)
    Observe the figure, sides stairs are expanding with above formula
    Time Complexity - O(1)
    Space Complexity - O(1)
    **/

public:
    long long coloredCells(int n) {
        long long N = n;
        return 1 + 2 * N * (N - 1);
    }
};