/**
Medium - DI String Match
https://leetcode.com/problems/di-string-match
Written By : LalitN97
**/

class Solution {
public:

    /**
    Idea : count all increments/decrements either of them and assign an initial increment and decrement value
    and iterate over the string again wherever you see an increment/decrement push it into the answer
    and increase the increment/ decrease the decreament.
    Initial Increment value = n - (count of increments);
    Initial Decrement value = Initial Increment Value - 1;
    Time Complexity - O(N)
    Space Complexity - O(N)
    where N is the size of input string
    **/

    vector<int> diStringMatch(string s) {
        int n = s.size();
        int incrCount = 0;
        for(char ch : s){
            if(ch == 'I') incrCount++;
        }
        int incrStart = n - incrCount;
        int decrStart = incrStart - 1;
        vector<int> perm(n+1);
        perm[0] = incrStart;
        for(int i = 1; i <= n; i++){
            if(s[i - 1] == 'I'){
                perm[i] = ++incrStart;
            }
            else{
                perm[i] = decrStart--;
            }
        }
        return perm;
    }
};