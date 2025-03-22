/**
Medium - Queens That Can Attack the King
https://leetcode.com/problems/queens-that-can-attack-the-king
Written By : LalitN97
**/

class Solution {
public:

    void queenPresent(bool queenExist[8][8], int xKing, int yKing, char axis, int dir, vector<vector<int>>& coordinates){
        int N = 8;
        int i = xKing;
        int j = yKing;
        if(axis == 'X'){
            while((dir == 1 ? (j < N) : (j >= 0)) && !queenExist[i][j]) j += dir;
            if((dir == 1 ? (j != N) : (j != -1))) coordinates.push_back({i, j});
            
        }
        else if (axis == 'Y'){
            while((dir == 1 ? (i < N) : (i >= 0)) && !queenExist[i][j]) i += dir;
            if((dir == 1 ? (i != N) : (i != -1))) coordinates.push_back({i, j});
        }
        else if (axis == 'Z'){
            while((dir == 1 ? (i < N && j < N) : (i >= 0 && j >= 0)) && !queenExist[i][j]){
                i += dir;
                j += dir;
            }
            if((dir == 1 ? (i != N && j != N) : (i != -1 && j != -1))) coordinates.push_back({i, j});
        }
        else{
            while((dir == 1 ? (i < N && j >= 0) : (i >= 0 && j < N)) && !queenExist[i][j]){
                i += dir;
                j -= dir;
            }
            if((dir == 1 ? (i != N && j != -1) : (i != -1 && j != N))) coordinates.push_back({i, j});
        }
    }

    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        bool queenExist[8][8];
        memset(queenExist, false, sizeof queenExist);
        for(vector<int> queen : queens){
            queenExist[queen[0]][queen[1]] = true;
        }

        vector<vector<int>> directAttackCoordinates;

        queenPresent(queenExist, king[0], king[1], 'X', 1, directAttackCoordinates);
        queenPresent(queenExist, king[0], king[1], 'X', -1, directAttackCoordinates);
        queenPresent(queenExist, king[0], king[1], 'Y', 1, directAttackCoordinates);
        queenPresent(queenExist, king[0], king[1], 'Y', -1, directAttackCoordinates);
        queenPresent(queenExist, king[0], king[1], 'Z', 1, directAttackCoordinates);
        queenPresent(queenExist, king[0], king[1], 'Z', -1, directAttackCoordinates);
        queenPresent(queenExist, king[0], king[1], 'R', 1, directAttackCoordinates);
        queenPresent(queenExist, king[0], king[1], 'R', -1, directAttackCoordinates);

        return directAttackCoordinates;
    }
};