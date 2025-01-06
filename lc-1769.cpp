/**
Medium - Minimum Number of Operations to Move All Balls to Each Box
https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/description/
Written By : LalitN97
**/

class Solution {
public:

    /**
    Idea : 
    For each index iterate over the rest of the indexes of the array and check if the element at that index is 1,
    calculate the distance of that '1' from the cur index. Do this for every one and sum up the absolute distances
    to find the anwer for each index.
    Time Complexity - O(N^2)
    Space Complexity - O(1)
    where N is the size of the input binary string.

    Using Prefix Sum : 
    we need to use the idea of cummulative sum. We need to store two arrays prefixSum and suffixSum where each
    index of the arrays will represent no of operations performed to collect all 1's from left and from right
    respectively.
    Once these arrays are prepared the answer to the ith query will be prefixSum[i] + suffixSum[i]
    Time Complexity - O(N)
    Space Complexity - O(N); // instead of 2 * N we can reuse prefixSum along with answer array
     to calculate suffixSum
    where N is the size of input string
    
    **/

    vector<int> minOperations(string boxes) {
        // int n = boxes.size();
        // vector<int> ans(n, 0);
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < n; j++){
        //         if(i != j && boxes[j] == '1'){
        //             ans[i] += abs(j - i);
        //         }
        //     }
        // }
        // return ans;

        int n = boxes.size();
        vector<int> ans(n, 0);
        // vector<int> prefixSum(n, 0); // to reduce the memory usage we can use ans array instead
        vector<int> suffixSum(n, 0);
        int nOnes = boxes[0] == '1';
        for(int i = 1; i < n; i++){
            // prefixSum[i] = prefixSum[i - 1] + nOnes;
            ans[i] = ans[i - 1] + nOnes;
            if(boxes[i] == '1') nOnes++;
        }
        nOnes = boxes[n - 1] == '1'; // reset to build suffixSum array
        for(int i = n - 2; i >= 0; i--){
            suffixSum[i] = suffixSum[i + 1] + nOnes;
            if(boxes[i] == '1') nOnes++;
        }

        for(int i = 0; i < n; i++){
            // ans[i] = prefixSum[i] + suffixSum[i];
            ans[i] += suffixSum[i];
        } 
        return ans;
    }
};