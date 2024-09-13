// https://leetcode.com/problems/xor-queries-of-a-subarray/

class Solution {
public:
    
    /**
    Logic : 
    build a prefix xor array whose ith term will contain the result of xor sum from 0th to ith index.
    use the same prefix xor array to answer q queries in O(1) time by using cor property where two same elements xor will be 0.
    To find the xor range from [i, j], we can get the prefix xor upto (i - 1)th and xor it with prefix xor upto (j)th element.
    Time Complexity - O(n + m), Space Complexity - O(n)
    where n is the arr.size() and m -> no of queries 
    **/
    
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int prefixXor[30001] = {0};
        memset(prefixXor, 0, sizeof prefixXor);
        for(int i = 0; i < arr.size(); i++){
            prefixXor[i + 1] = prefixXor[i] ^ arr[i];
        }
        
        vector<int> ans;
        for(auto query : queries){
            ans.push_back(prefixXor[query[1] + 1] ^ prefixXor[query[0]]);
        }
        
        return ans;
    }
};