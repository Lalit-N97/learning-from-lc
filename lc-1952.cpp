/**
Easy - Three Divisors
https://leetcode.com/problems/three-divisors/
Written By : LalitN97
**/

class Solution {
public:
    
    /**
    Idea : other way to think about this problem is to check if the input number is a perfect square with 
    its square root as a prime number. We can find the prime number using seive of erastosthenes.
    Time Complexity - O(log(logN))
    Space Complexity - O(sqrt(N))
    where N is the input number
    **/
    
    void seive(bool* primes, int n){
        primes[0] = false;
        primes[1] = false;
        for(int i = 2; i <= n; i++){
            if(primes[i]){
                for(int j = i*2; j <= n; j+=i){
                    primes[j] = false;
                }
            }
        }
    }
    
    bool isThree(int n) {
        bool primes[101];
        memset(primes, true, sizeof primes);
        seive(primes, 100);
        double root = sqrt(n);
        int intRoot = root;
        if(root == intRoot) {
            return primes[intRoot];
        }
        return false;
    }
};