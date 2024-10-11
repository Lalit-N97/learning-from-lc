// https://leetcode.com/problems/valid-boomerang/

/**
Logic Area of triangle formed by 3 points using determinant formulae
**/

class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        double x1 = points[0][0];
        double y1 = points[0][1];
        double x2 = points[1][0];
        double y2 = points[1][1];
        double x3 = points[2][0];
        double y3 = points[2][1];
        double area = 0.5 * (1 * (x2 * y3 - (y2 * x3)) - x1 * (y3 - y2) + y1 * (x3 - x2));
        return area != 0;
    }
};