/**
Medium - Minimum Operations to Make a Uni-Value Grid
https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid
Written By : LalitN97
**/

class Solution {
public:

    /**
    Idea : Sort the matrix as 1D array in increasing order and choose a median index and try to come up with the 
    no of operations we need to perfrom in order to change all the values to median value.
    Time Complexity - O(N*M * Log(M*N))
    Space Complexity - O(N*M)
    **/

    void print(vector<int>& nums){
        for(int num : nums) cout << num << ",";
        cout << "\n";
    }

    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size();
        int m = grid[0].size();
        int nOperations = 0;
        int* nums = new int[n*m];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int idx = m * i + j;
                nums[idx] = grid[i][j];
            }
        }
        sort(nums, nums + n*m);
        int median = nums[(n*m)/2];
        for(int i = 0; i < n*m; i++){
            if(abs(nums[i] - median)%x != 0) return -1;
            nOperations += abs(nums[i] - median)/x;
        }
        return nOperations;
    }
};