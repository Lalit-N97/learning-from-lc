/**
Medium - Check if Every Row and Column Contains All Numbers
https://leetcode.com/problems/check-if-every-row-and-column-contains-all-numbers/
Written By : LalitN97
**/

class Solution {
public:

    /**
    Idea : iterate over the the main diagonal of the square matrix
    and at each point in the diagonal check if that row and column contains the duplicate, if yes then return false
    else return true;
    Time Complexity - O(N*N)
    Space Complexity - O(N)
    where N is the no of rows/columns in the input matrix
    **/

    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n; i++){
            bitset<102> isDuplicateInRow;
            bitset<102> isDuplicateInCol;
            for(int j = 0; j < n; j++){ // check the ith row
                if(isDuplicateInRow[matrix[i][j]] & 1) return false;
                isDuplicateInRow.set(matrix[i][j]);
            }
            for(int j = 0; j < n; j++){ // check the ith col
                if(isDuplicateInCol[matrix[j][i]] & 1) return false;
                isDuplicateInCol.set(matrix[j][i]);
            }
        }
        return true;
    }
};