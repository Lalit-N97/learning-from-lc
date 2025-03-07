/**
Medium - Closest Prime Numbers in Range
https://leetcode.com/problems/closest-prime-numbers-in-range
Written By : LalitN97
**/

class Solution {
public:

    /**
    Idea : find the prime numbers between range [left, right]. and take the first pair who difference is smallest
    among the prime numbers present between left to right in ascending order.
    Use sieve of Erastosthenes to find prime numbers from 0 to 10^6
    Time Complexity : O(N * Log(LogN))
    Space Complexity : O(N)
    where N is the input range difference
    **/

    void sieveOfErastosthenes(bool *prime, int n){
        prime[0] = false;
        prime[1] = false;
        for(int p = 2; p * p < n; p++){
            if(prime[p] == true){
                for(int j = p * p; j < n; j += p){
                    prime[j] = false;
                }
            }
        }
    }

    vector<int> closestPrimes(int left, int right) {
        const int N = 1000001;
        bool prime[N];
        fill(prime, prime + N, true);
        sieveOfErastosthenes(prime, N);
        int minFirst = left - 1;
        int minSecond = right + 1;
        int first = -1;
        int second = -1;
        for(int i = left; i <= right; i++){
            if(prime[i] == true){
                if(first == -1){
                    first = i;
                    minFirst = first;
                }
                else if(second == -1){
                    second = i;
                    minSecond = second;
                }
                else{
                    first = second;
                    second = i;
                    if((second - first) < (minSecond - minFirst)){
                        minFirst = first;
                        minSecond = second;
                    }
                }
            }
        }
        if(minSecond == right + 1) return {-1, -1};
        return {minFirst, minSecond};
    }
};