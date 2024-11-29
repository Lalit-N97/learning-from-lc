/**
Easy - Count of Matches in Tournament
https://leetcode.com/problems/count-of-matches-in-tournament/
Author : LalitN97
**/


class Solution {
public:
    
    /**
    Logic : 
    Keep reducing the number of teams by half as they progress in the tournament until only 1 team remains in the tournament
    Time Complexity - O(Log N)
    Space Complexity - O(1)
    
    OR 
    This question is also interpreted like this - one team plays with other team either loose (and get out of the tounament)
    and win (keep playing further matches). So the only one winning team will always play matches with the other team.
    and those no of matches will be n - 1
    So the answer will always be n-1 matches played.
    Time Complexity - O(1)
    Space Complexity - O(1)
    
    **/
    
    int numberOfMatches(int n) {
        // int nPlayedMatches = 0;
        // while(n > 1){
        //     nPlayedMatches += (n >> 1);
        //     n = ((n - 1) >> 1) + 1; // (n - 1) / 2 + 1 always irrespective or even or odd n.To prove it - take 2 exaple.
        // }
        // return nPlayedMatches;
        return n - 1;
    }
};