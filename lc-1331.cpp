// https://leetcode.com/problems/rank-transform-of-an-array/

class Solution {
public:
    
    /**
    
    Logic : 
    1. Take a ordered_map to store the elements of input arr. 
    2. Once all the elements are stored in the map. Iterate over the map to update the rank of elements
    3. Once the rank is updated, iterate over the input arr to fetch and store the ranks of array elements using rank ordered map.
    Time Complexity - O(N * LogN), Space Complexity - O(N)
    **/
    
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans;
        ans.reserve(n); // to set the capacity to n so that it will not perform doubling operation once capacity is full which is the cause of ineffiecientness of the program
        if(n == 0) return ans;
        map<int, int> rank;
        for(int i = 0; i < n; i++) rank[arr[i]] = 0;
        int j = 1;
        for(auto it : rank){
            rank[it.first] = j;
            j++;
        }
        
        for(int i = 0; i < n; i++){
            ans.push_back(rank[arr[i]]);
        }
        
        return ans;
    }
};