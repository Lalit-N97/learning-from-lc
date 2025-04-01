/**
Medium - Solving Questions With Brainpower
https://leetcode.com/problems/solving-questions-with-brainpower
Written By : LalitN97
**/

class Solution {
public:

    /**
    Idea : recusively pick and unpick questions as you encounter will give you a branched recursive binary tree
    with time - O(2^N)
    On observing a test case it seems the problem has overlapping smaller subproblems and since we are taking max
    from each subproblem so it gives optimal substructure
    So now we can memoize the overlapping subproblems answer So that each subproblem is computed once reducing the time
    to O(N).
    Space Complexity - O(N);
    where N is the size of memopad
    **/

    long long collectPoints(vector<vector<int>>& q, int i, int n, long long* memo){
        if(i >= n) return 0;
        if(memo[i] != -1) return memo[i];
        memo[i] = max((long long)q[i][0] + collectPoints(q, q[i][1] + i + 1, n, memo), collectPoints(q, i + 1, n, memo));
        return memo[i];
    }

    long long mostPoints(vector<vector<int>>& questions) {
        // long long memo[100001];
        // memset(memo, -1, sizeof memo);
        // return collectPoints(questions, 0, questions.size(), memo);
        

        // bottom-up approach 
        long long dp[100001];
        memset(dp, -1, sizeof dp);
        // dp[i] represent the maximum collected points from i to n;
        
        int n = questions.size();
        // base case 
        dp[n - 1] = questions[n - 1][0];
        for(int i = n - 2; i >= 0; i--){
            dp[i] = dp[i + 1];
            int nextIdx = questions[i][1] + i + 1;
            dp[i] = max(dp[i + 1], questions[i][0] + (nextIdx > n ? 0 : dp[nextIdx]));
        }
        return dp[0];
    }
};