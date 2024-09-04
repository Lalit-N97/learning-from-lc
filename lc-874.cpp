// https://leetcode.com/problems/walking-robot-simulation/

/**
Simulate the solution as per the said problem statement
Need to keep multiple variables to track directions and 
Time - O(k * N * log N) where k = 9, Space - O(N)
**/

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        map<pair<int, int>, bool> obstacle;
        for(int i = 0; i < obstacles.size(); i++) obstacle[make_pair(obstacles[i][0], obstacles[i][1])] = true;
        
        // 0 means no movement
        // 1 means moving to positive direction
        // 2 means moving to negative direction
        int dirX = 0;
        int dirY = 1;
        
        int maxDist = 0; // a global maximum distance covered by the robot at some point
        int x = 0; // initially both x and y is at origin
        int y = 0;
        for(int i = 0; i < commands.size(); i++){
            int ele = commands[i];
            // rotate 90 degress right
            if(ele == -1){
                if(dirX != 0){
                    if(dirX == -1){
                        dirY = 1;
                    }
                    else{
                        dirY = -1;
                    }
                    dirX = 0;
                }
                else{
                    if(dirY == -1){
                        dirX = -1;
                    }
                    else{
                        dirX = 1;
                    }
                    dirY = 0;
                }
            }
            // rotate 90 degrees left
            else if(ele == -2){
                if(dirX != 0){
                    if(dirX == -1){
                        dirY = -1;
                    }
                    else{
                        dirY = 1;
                    }
                    dirX = 0;
                }
                else{
                    if(dirY == -1){
                        dirX = 1;
                    }
                    else{
                        dirX = -1;
                    }
                    dirY = 0;
                }
            }
            else{
                // let's handle the obstacle part in the for loop
                int k = 1;
                bool outOfLoopFlag = false;
                const int xi = x;
                const int yi = y;
                for(; k <= ele; k++){
                    if(dirX != 0){
                        if(obstacle[make_pair(xi + dirX * k, y)] == true){
                            x += (dirX) * (k - 1);
                            outOfLoopFlag = true;
                            break;
                        }
                    }
                    else{
                        if(obstacle[make_pair(x, yi + dirY * k)] == true){
                            y += (dirY) * (k - 1);
                            outOfLoopFlag = true;
                            break;
                        }
                    }
                }
                if(!outOfLoopFlag){
                    x += (dirX)*ele;
                    y += (dirY)*ele;
                }
                maxDist = max(maxDist, x*x + y*y);
            }
        }
        return maxDist;
    }
};