// Medium - Most Beautiful Item for Each Query
// https://leetcode.com/problems/most-beautiful-item-for-each-query/

class Solution {
public:
    
    /**
    Logic : 
    Sort the items vector w.r.t. price.
    In sorted vector we can find our query price index using binary search - (1)
    use a prefix array to find the maximum beauty upto some index. - (2)
    Every query result can be fetch by find the index from eqn(1) and getting the max beauty from eqn(2)
    Time Complexity - O(Q*logN)
    Space Complexity - O(Q)
    where Q is the size of the input queries vector
    and N is the no of rows in input items vector
    **/
    
    int getLessPriceIdx(vector<vector<int>> &items, int price){
        int idx = -1;
        int start = 0;
        int end = items.size() - 1;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(price < items[mid][0] ){
                end = mid - 1;
            }
            else {
                start = mid + 1;
                idx = mid;
            }
        }
        return idx;
    }
    
    void print(vector<vector<int>>& items){
        for(int i = 0; i < items.size(); i++){
            for(int j = 0; j < items[i].size(); j++) cout << items[i][j] << " ";
            cout << "\n";
        }
    }
    
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = items.size();
        sort(items.begin(), items.end());
        vector<int> prefixMax(n + 1, 0);
        for(int i = 0; i < n; i++) prefixMax[i + 1] = max(prefixMax[i], items[i][1]);
        
        int q = queries.size();
        vector<int> maxBeauty(q, 0);
        for(int i = 0; i < q; i++){
            int price = queries[i];
            int idx = getLessPriceIdx(items, price);
            maxBeauty[i] = prefixMax[idx + 1];
        }
        return maxBeauty;
    }
};