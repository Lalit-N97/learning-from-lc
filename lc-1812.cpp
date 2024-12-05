/**
Medium - Determine Color of a Chessboard Square
https://leetcode.com/problems/determine-color-of-a-chessboard-square/
Author : LalitN97
**/

class Solution {
public:
    
    /**
    
    Logic : just look at the chessboard, you'll find the pattern that for (a, c, e, g) letters the 
    the even y coordinates will give white squares and for (b, d, f, h) letters the 
    odd y coordingates will give white squares.
    Time Complexity - O(4)
    Space Complexity - O(4)
    where 4 is the maximum no of letters we need compare with.
    
    **/
    
    bool squareIsWhite(string coordinates) {
        char oddAlpha[4] = {'b', 'd', 'f', 'h'};
        for(char ch : oddAlpha){
            if(ch == coordinates[0]){
                if((coordinates[1] - '0') & 1) return true;
                else return false;
            }
        }
        if((coordinates[1] - '0') & 1) return false;
        return true;
    }
};