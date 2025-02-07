/**
Medium - Find the Number of Distinct Colors Among the Balls
https://leetcode.com/problems/find-the-number-of-distinct-colors-among-the-balls
Written By : LalitN97
**/

class Solution {
public:

    /**
    Idea : while iterating the queries store ball with its latest color and the frequency of each color
    painted in the balls upto certain traversal.
    For a query, if the current ball is already painted then reduce the frequency of painted color by 1
    and if the frequency of that already painted color reduced to 0 then DistinctColors will be reduced 
    by 1 and now paint the ball with new color, increase the color's frequency, if the new color
    frequency becomes 1 then distinctColors will increase by 1. 
    if the current ball is uncolored then increase the frequency of the new color and if this color's freq
    becomes 1 then increase nDistinctColors by 1.
    Time Complexity - O(N)
    Space Complexity - O(N)
    where N is the size of the input queries.
    **/

    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> ballColor;
        unordered_map<int, int> colorFreq;
        vector<int> distinctColor;
        int nDistinctColors = 0;
        for(vector<int> query : queries){
            int ball = query[0];
            int newColor = query[1];
            int oldColor = ballColor[ball];
            if(oldColor == 0){ // uncolored ball
                colorFreq[newColor]++;
                if(colorFreq[newColor] == 1) nDistinctColors++;
            }
            else if(oldColor != newColor){
                colorFreq[oldColor]--;
                if(colorFreq[oldColor] == 0) nDistinctColors--;
                colorFreq[newColor]++;
                if(colorFreq[newColor] == 1) nDistinctColors++;
            }
            distinctColor.push_back(nDistinctColors);
            ballColor[ball] = newColor;
        }
        return distinctColor;
    }
};