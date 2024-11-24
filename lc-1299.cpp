
/**
Easy - Replace Elements with Greatest Element on Right Side
https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/
Author : LalitN97
**/

class Solution {
public:
    
    /**
    Logic : 
    traverse from back side of the input array (from left to right) and track the maximum value upto current 
    index's right and replace the maximum value into the current index element but before that ensure to save
    the max upto current index and repeat the process until you reach to the extreme left
    Time Complexity - O(N)
    Space Complexity - O(1)
    **/
    
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        int prevMax = arr[n - 1];
        arr[n - 1] = -1;
        for(int i = n - 2; i >= 0; i--){
            int tempVal = arr[i];
            arr[i] = prevMax;
            prevMax = max(prevMax, tempVal);
        }
        return arr;
    }
};