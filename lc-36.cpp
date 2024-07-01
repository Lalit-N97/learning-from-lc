// https://leetcode.com/problems/valid-sudoku/

class Solution {
public:
    
    // check whether the val is present in the row(true) or not(false)
    bool checkRow(vector<vector<char>>& board, int row, int col, char val){
        int n = board.size();
        for(int j = 0; j < n; j++){
            if(j != col && val == board[row][j]) return false;
        }
        return true;
    }
    
    // check whether the val is present in the col(true) or not(false)
    bool checkCol(vector<vector<char>>& board, int row, int col, char val){
        int n = board.size();
        for(int i = 0; i < n; i++){
            if(i != row && val == board[i][col]) return false;
        }
        return true;
    }
    
    // check whether the val is present in the 3X3 block(true) or not(false)
    bool checkBlock(vector<vector<char>>& board, int row, int col, char val){
        int n = board.size();
        int firstCellRowInBlock = row - row%3;
        int firstCellColInBlock = col - col%3;
        for(int i = firstCellRowInBlock; i < firstCellRowInBlock + 3; i++){
            for(int j = firstCellColInBlock; j < firstCellColInBlock + 3; j++){
                if(i != row && j != col && val == board[i][j]) return false;
            }
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        // A valid sodoku is the matrix of 9 X 9 where the 
        // digits present should be present once in a column, in arow and in each 3 X 3 box
        int n = board.size();
        for(int row = 0; row < n; row++){
            for(int col = 0; col < n; col++){
                char val = board[row][col];
                if(val != '.'){
                    bool check1 = checkRow(board, row, col, val);
                    bool check2 = checkCol(board, row, col, val);
                    bool check3 = checkBlock(board, row, col, val);
                    bool isValid = check1 && check2 && check3;
                    if(!isValid) return false;
                }
            }
        }
        return true;
    }
};