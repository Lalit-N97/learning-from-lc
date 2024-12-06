/**
Medium - Maximum Number of Integers to Choose From a Range I
https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i/
Author : LalitN97
**/

class Solution {
public:
    
    /**
    Intuition : 
    just observe some test cases and you'll find the more smaller number you pick the more chances 
    you have to get more numbers which contributes to sum less than or equal to maxSum. This boils down
    to thinking.
    store the banned integers in boolean map so that you'll get O(1) to check whether we need to pick 
    the current element from 1 to n (inclusive) or not. Now simulate 1 to n numbers as a for loop and
    for each number check if it is eligible number, if it is eligible number then pick the number and 
    reduce the number from the sum. Count all those numbers in each iteration if that number will 
    contribute and still the reduced maxSum is greater than or equal to 0.
    Time Complexity - O(N)
    Space Complexity - O(N)
    where N is the maximum of (max element in input array banned, n)
    **/
    
    int maxCount(vector<int>& banned, int n, int maxSum) {
        bool banHash[10001];
        memset(banHash, false, sizeof banHash);
        for(int bannedInt : banned) banHash[bannedInt] = true;
        int countValidInts = 0;
        for(int i = 1; i <= n; i++){
            if(banHash[i] == true) continue; 
            maxSum -= i;
            if(maxSum < 0){
                break;
            }
            countValidInts++;
        }
        return countValidInts;
    }
};