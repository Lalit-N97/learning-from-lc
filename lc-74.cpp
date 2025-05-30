/**
Medium - Search a 2D Matrix
https://leetcode.com/problems/search-a-2d-matrix
Written By : LalitN97
**/

class Solution {
public:

    /**
    Idea : Since the array is sorted in non decreasing order in each row and each column is sorted in strictly increasing order
    We can look for our target in the first column to find it directly or it lies in some row.
    Once row is figured out we can find it in that row both using Binary Search which leads to O(Log(m) + log(n)) time
    but using the above approach we need to write two for loops. Code will be verbose.

    Other approach will also has the same no of iterations as that of first approach but this way will use only single loop
    to iterate over the entire matrix.
    We know that every row and column index is assiciated with a number i.e. arr[i][j] == arr[i * m + j] where m is the no of
    columns. We also know our search space which is 0 to n*m - 1. we can apply binary search over the avaliable indexes
    (seach space) and generate row and column based on i and j using i = NUM/m and j = NUM%m. where NUM = i * M + j
    Time Complexity - log(n*m) which is same as that of log(m) + log(n)
    Space Complexity - O(n)
    where n is the no of rows and m is the no of columns in the matrix
    **/

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int start = 0;
        int end = n * m - 1;
        while(start <= end){
            int mid = start + (end - start)/2;
            int row = mid/m;
            int col = mid%m;
            if(matrix[row][col] == target) return true;
            else if(target > matrix[row][col]) start = mid + 1;
            else end = mid - 1;
        }
        return false;
    }
};