// https://leetcode.com/problems/matrix-diagonal-sum/

class Solution {
public:
    
    /**
    Logic : iterating over the primary diagonal and taking the sum. Also taking the sum of secondary diagonal elements using mirror row. Care is needed incase at any point the mirro row and the current row becomes equal. At this point add the element only once in the sum.
    Time Complexity - O(N), Space Complexity - O(1)
    where N is the no of rows in the square matrix
    **/
    
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int i = 0;
        int j = 0;
        int sumOfDiagonals = 0;
        while(i < n && j < n){
            sumOfDiagonals += mat[i][j];
            int mirrorI = n - 1 - i;
            if(i != mirrorI) sumOfDiagonals += mat[mirrorI][j];
            i++;
            j++;
        }
        return sumOfDiagonals;
    }
};