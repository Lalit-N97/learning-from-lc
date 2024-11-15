// Easy - Defuse the Bomb
// https://leetcode.com/problems/defuse-the-bomb/

class Solution {
public:
    
    /**
    Logic : 
    use sliding window to calculcate the sum upto k items and then for each element slide the window to get furhter sums for each element.
    Time Complexity - O(N + k)
    Space Complexity - O(N)
    where N is the size of input array
    and k is the window size.
    **/
    
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n, 0);
        int sum = 0;
        if(k > 0){
            for(int i = 0; i < k; i++) sum += code[i];
            for(int i = 0; i < n; i++) {
                ans[i] = sum = sum - code[i] + code[(i + k)%n];
                // above line is similar to below two lines
                // sum = sum - code[i] + code[(i + k)%n];
                // ans[i] = sum;
            }
        }
        else if(k < 0){
            for(int i = n - 1; i >= n + k; i--) sum += code[i];
            for(int i = n - 1; i >= 0; i--){
                ans[i] = sum = sum - code[i] + code[(i + k + n)%n];
            }
        }
        return ans;
    }
};