/**
Medium - First Completely Painted Row or Column
https://leetcode.com/problems/first-completely-painted-row-or-column
Written By : LalitN97
**/

class Solution {
public:

    /**
    Idea : 
    take two arrays row of size m and col of size n. Where row[i] represent the count of the no of elements
    present in the ith row and if the ith row has m elements present then which means all the elements of the ith
    row has been painted.
    Similarly with col array. 
    {
    We can also prepare below storage option :
    Instead of using unordered_map to store pair of indices against their element. we can store a single integer
    against the element (i.e. the index while iterating from 0 to m*n - 1) elements of matrix.
    To retrieve the pair of indices we can do (i % nRows, i % nCols 
    }
    Time complexity - O(M * N)
    Space Complexity - O(M * N)
    where M is the no of rows in input matrix
    and N is the no of columns in input matrix
    **/

    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int nRows = mat.size();
        int nCols = mat[0].size();
        vector<int> nElementsInRow(nRows, 0);
        vector<int> nElementsInCol(nCols, 0);
        unordered_map<int, pair<int, int>> indicesMap;
        for(int i = 0; i < nRows; i++){
            for(int j = 0; j < nCols; j++){
                indicesMap[mat[i][j]] = make_pair(i, j);
            }
        }

        for(int idx = 0; idx < arr.size(); idx++){
            int ele = arr[idx];
            int row = indicesMap[ele].first;
            int col = indicesMap[ele].second;
            nElementsInRow[row]++;
            nElementsInCol[col]++;
            if(nElementsInRow[row] == nCols || nElementsInCol[col] == nRows) return idx;
        }
        return arr.size();
    }
};