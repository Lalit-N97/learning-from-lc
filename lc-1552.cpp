/**
Medium - Magnetic Force Between Two Balls
https://leetcode.com/problems/magnetic-force-between-two-balls
Written By : LalitN97
**/

class Solution {
public:

    /**
    Idea : question says adjacent balls should be as far as possible.
    Take a magnetic force m, and try to place all the balls under this m magnetic force.
    If you are able to place all the balls then increase m and try placing the balls again.
    if not able to place all the balls then decrease m and try placing the balls.
    when you are no more able to place the balls after certain max force m, then that is our answer.
    This placing the balls takes linear time and then choosing the force m will take another linear time.
    So total time will be (N * M)
    Choosing the force m can be done using binary search in a given search space [minForce, maxForce]
    Time Complexity - O(N * log(M))
    Space Complexity - O(1)
    **/

    bool canPlace(vector<int>& positions, int nBalls, int force){
        int nBallsPlaced = 1;
        int prevIdx = 0;
        for(int i = 1; i < positions.size(); i++){
            if(positions[i] - positions[prevIdx] >= force){
                prevIdx = i;
                nBallsPlaced++;
            }
            if(nBallsPlaced >= nBalls) return true;
        }
        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(), position.end());
        int minDiff = INT_MAX;
        int prev = 0;
        for(int pos : position){
            minDiff = min(minDiff, pos - prev);
            prev = pos;
        }

        int start = minDiff;
        int end = position[n - 1] - position[0];
        int maxForce = 0;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(canPlace(position, m, mid)){
                maxForce = mid;
                start = mid + 1;
            }
            else end = mid - 1;
        }
        return maxForce;
    }
};