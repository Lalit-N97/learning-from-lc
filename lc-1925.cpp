/**
Easy - Count Square Sum Triples
https://leetcode.com/problems/count-square-sum-triples/
Written By : LalitN97
**/

class Solution {
public:
    
    /**
    Think of iterating over all the possible pairs a and b and try to get value of a^2 + b^2
    squareroot of this value should be integer <= n. In that case count the triplet.
    Squareroot can be found using binary search. try finding sqaure root with binary search.
    Time Complexity - O(N * N * Log10N)
    Space Comlpexity - O(1)
    where N is the input number
    
    ------------NOT IMPLEMENTED--------------
    This time complexity can be reduced to O(N*N) by storing all the squares from 1 to n in an array
    and when calculating (a*a + b*b) just check whether this value is present over the stored array
    Time Complexity - O(N*N)
    Space Complexity - O(N)
    
    **/
    
    double mySqrt(long long n){
        double intPart = 0;
        long long start = 1;
        long long end = n - 1;
        while(start <= end){
            long long mid = start + (end - start)/2;
            if(mid * mid == n){
                intPart = mid;
                break;
            }
            else if(mid * mid < n){
                intPart = mid;
                start = mid + 1;
            }
            else end = mid - 1;
        }
        
        double ans = intPart;
        int precision = 5;
        double inc = 0.1;
        double N = n;
        for(int i = 0; i < precision; i++){
            while(ans * ans <= N){
                ans += inc;
            }
            ans -= inc;
            inc *= 0.1;
        }
        return ans;
    }
    
    int countTriples(int n) {
        cout << mySqrt(n);
        int squareTriples = 0;
        for(int a = 1; a <= n; a++){
            for(int b = 1; b <= n; b++){
                double c = mySqrt(a*a + b*b);
                if(c <= n && c == floor(c)) squareTriples++;
            }
        }
        return squareTriples;
    }
};