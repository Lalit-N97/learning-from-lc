/**
Medium - Grid Game
https://leetcode.com/problems/grid-game/
Written By : LalitN97
**/

class Solution {
public:

    /**
    Idea : Robots can only move eigher right or down. Since there are two rows, which means only one down
    movement is possible. If the robots moves down it need to move all the way right to reach its destination.
    By observing this, we see that we need to find ways to run the first robot so that second robot points
    collection is minimized hence we concludeto find minimum points collected by second robot at each
    position in first row, if in that position the first robots moves down.
    we can use suffix sum on 1st row to see what all points second robot can take.
    if we move downwards from (0, i)th position.
    Time Complexity - O(N)
    Space Complexity - O(N)
    **/

    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        long long suffixSum[50002];
        memset(suffixSum, 0, sizeof suffixSum);
        for(int i = n - 1; i >= 0; i--){
            if(i == n - 1) suffixSum[i] = grid[0][i];
            else suffixSum[i] = suffixSum[i + 1] +  grid[0][i];
        }

        long long minPointsCollected = 1e10;
        long long secondRowSum = 0;
        for(int downPos = 0; downPos < n; downPos++){
            long long pointsCollectedBy2 = max(suffixSum[downPos + 1], secondRowSum);
            minPointsCollected = min(minPointsCollected, pointsCollectedBy2);
            // cout << pointsCollectedBy2 << " " << minPointsCollected << "\n";
            secondRowSum += grid[1][downPos];
        }
        return minPointsCollected;
    }
};