// Medium - Difference Between Ones and Zeros in Row and Column
// https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column/

class Solution {
public:
    
    /**
    Logic : 
    We need to store the no of ones for each row and column in an array by precomputing them while iterating over the array.
    Use those precomputed values to form required difference matrix
    Time Complexity - O(N * M)
    Space Complexity - O(N + M)
    where N is the no of rows in the input matrix
    and M is the no of columns in the input matrix
    **/
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<int> onesRow(n, 0);
        vector<int> onesCol(m, 0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                onesRow[i] += grid[i][j];
                onesCol[j] += grid[i][j];
            }
        }
        
        vector<vector<int>> diff(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                diff[i][j] += onesRow[i] + onesCol[j] - (n - onesRow[i]) - (m - onesCol[j]);
            }
        }
        return diff;
    }
};