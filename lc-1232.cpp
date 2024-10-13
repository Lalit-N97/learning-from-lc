// https://leetcode.com/problems/check-if-it-is-a-straight-line/

class Solution {
public:
    
    /**
    Logic : use first point as base and calculate the slope of lines formed by each points 
    apart from baseX and baseY. If all the points lie on a single line then slope of each points are
    same otherwise the slope of some points will be different.
    Time Complexity - O(N), Space Complexity - O(1)
    
    **/
    
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        double baseX = coordinates[0][0];
        double baseY = coordinates[0][1];
        double prevSlope = -2;
        for(int i = 1; i < coordinates.size(); i++){
            double x = coordinates[i][0];
            double y = coordinates[i][1];
            double slope = (y - baseY)/(x - baseX);
            if((x - baseX) == 0) slope = -1;
            if(prevSlope != -2 && slope != prevSlope) {
                return false;
            }
            prevSlope = slope;
        }
        return true;
    }
};