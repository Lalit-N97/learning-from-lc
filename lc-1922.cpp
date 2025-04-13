/**
Medium - Count Good Numbers
https://leetcode.com/problems/count-good-numbers
Written By : LalitN97
**/

class Solution {
public:

    /**
    Idea : we can look at some examples and figure out that the no of good string are equal to 
    5^half for even places * 4^half for odd places. 
    Approach : implement the power function recursively or through bitwise operation.
    Time Complexity - O(logN)
    Space Complexity - O(logN) recursively
    Space Complexity - O(1) iteratively using bitwise operation
    where N is the input length of the string which we need to make GOOD.
    **/

    int powerRec(long long a, long long n, long long MOD){
        if(n == 0) return 1;
        long long subAns = powerRec(a, n/2, MOD);
        if(n & 1) return (((subAns * subAns) % MOD) * a) % MOD;
        return (subAns * subAns) % MOD;
    }

    int powerItr(long long a, long long n, long long MOD){
        // iterate over the exponenent in binary and make the base bigger by multiplying itself with itself at every
        // iteration. Take the base at a point where the binary value of n is 1.
        long long ans = 1;
        while(n){
            if(n & 1) ans = (ans * a) % MOD;
            n >>= 1;
            a = (a % MOD * a % MOD) % MOD;
        }
        return ans;
    }

    int countGoodNumbers(long long n) {
        long long MOD = (long long)1e9 + 7;
        return ((long long)powerItr(5, n/2 + n%2, MOD) * (long long)powerItr(4, n/2, MOD)) % MOD;
    }
};