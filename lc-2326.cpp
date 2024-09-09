// https://leetcode.com/problems/spiral-matrix-iv/

/**
Logic : 
Used 4 variable to set boundaries of row and columns 
while iterating(fiiling) matrix from left to right or top to bottom updating the 
boundaries.
Time Complexity - O(N), Space Complexity - O(N*N) [space for 2D vector]

**/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        int rowStart = 0;
        int colStart = 0;
        int rowEnd = m - 1;
        int colEnd = n - 1;
        vector<vector<int>> matrix(m, vector<int>(n, -1));
        while(rowStart <= rowEnd && colStart <= colEnd && head != NULL){
            if(rowStart <= rowEnd && colStart <= colEnd){
                // fill the row from left to right
                for(int i = colStart; head != NULL && i <= colEnd; i++){
                    matrix[rowStart][i] = head->val;
                    head = head->next;
                }
                // Since one row is finished then change the row by incrementing it.
                rowStart++;
            }
            
            if(rowStart <= rowEnd && colStart <= colEnd){
                // move from top to bottom 
                for(int i = rowStart; head != NULL && i <= rowEnd; i++){
                    matrix[i][colEnd] = head->val;
                    head = head->next;
                }
                colEnd--;
            }
            
            if(rowStart <= rowEnd && colStart <= colEnd){
                // move from right to left
                for(int i = colEnd; head != NULL && i >= colStart; i--){
                    matrix[rowEnd][i] = head->val;
                    head = head->next;
                }
                rowEnd--;
            }
            
            if(rowStart <= rowEnd && colStart <= colEnd){
                // move from bottom to top
                for(int i = rowEnd; head != NULL && i >= rowStart; i--){
                    matrix[i][colStart] = head->val;
                    head = head->next;
                }
                colStart++;
            }
            
        }
        return matrix;
    }
};