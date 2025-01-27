/**
Medium - Subrectangle Queries
https://leetcode.com/problems/subrectangle-queries
Written By : LalitN97
**/

/**
Idea : simulate what has been ask using Brute Force
Another approach : where you will track(store) every update in an array with their positions so that 
when the getValue() function is called you can track back in the updates tracker from backwards and see if the
current row and col for which getValue() function is called falls under any of the updates tracker from backwards
if yes, then return the newValue otherwise return the value from matrix.
Time Complexity :
    constructor - O(M*N)
    updateSubQueries - O(1)
    getValue - O(no of updateSubqueries() calls upto current getValue() function call)
Space Complexity - O(M * N)
where M is the no of columns and N is the no of rows of the rectangle input 2D array
**/

class SubrectangleQueries {
public:

    vector<vector<int>> matrix;
    vector<vector<int>> updates;

    SubrectangleQueries(vector<vector<int>>& rectangle) {
        int n = rectangle.size();
        int m = rectangle[0].size();
        for(int i = 0; i < n; i++){
            vector<int> row(m);
            for(int j = 0; j < m; j++) row[j] = rectangle[i][j];
            matrix.push_back(row);
        }
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        updates.push_back({row1, col1, row2, col2, newValue});
    }
    
    int getValue(int row, int col) {
        for(int i = updates.size() - 1; i >= 0; i--){
            if(row >= updates[i][0] && row <= updates[i][2] && col >= updates[i][1] && col <= updates[i][3]) return updates[i][4];
        }
        return matrix[row][col];
    }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */