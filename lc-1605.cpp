/**
Medium - Find Valid Matrix Given Row and Column Sums
https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/
Written By : LalitN97
**/

class Solution {
public:

    /**
    Idea : observe a 3 * 3 example you will get the intuition to iterate over the matrix rom left to right then
    top to bottom. While at the current index [i, j], place the minimum of rowSum[i] and colSum[j] and reduce this
    minimum from both rowSum[i] and colSum[j], do this until all the elements are place in a row * col size matrix
    Time Complexity - O(N^2)
    Space Complexity - O(N^2)
    **/

    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int nRows = rowSum.size();
        int nCols = colSum.size();
        vector<vector<int>> potentialMatrix(nRows, vector<int>(nCols, 0));
        for(int row = 0; row < nRows; row++){
            for(int col = 0; col < nCols; col++){
                int minVal = min(rowSum[row], colSum[col]);
                potentialMatrix[row][col] = minVal;
                rowSum[row] -= minVal;
                colSum[col] -= minVal;
            }
        }
        return potentialMatrix;
    }
};