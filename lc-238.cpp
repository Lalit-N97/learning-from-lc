/**
Medium - Product of Array Except Self
https://leetcode.com/problems/product-of-array-except-self
Written By : LalitN97
**/

class Solution {
public:

    /**
    Idea : Since we can't use division we cannot appraoch the problem with all elements products and then divide it with
    self element. Now we can follow an approach where we can have prefixProducts upto i and suffixProducts upto i.
    The answer to an element i will be prefixProduct[i - 1] * suffixProduct[i + 1]
    Time Complexity - O(N)
    Space Complexity - O(N) -- use space for only suffixProduct and on the fly calculate the prefixProduct 
    OR rather use space for suffixProduct and fill the ith answer at suffixProduct array only and return it
    where N is the size of input array.
    **/

    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> suffixProduct(n, 1);
        for(int i = n - 1; i >= 0; i--){
            suffixProduct[i] = (i == n - 1 ? 1 : suffixProduct[i + 1]) * nums[i];
        }

        int prefixProd = 1;
        for(int i = 0; i < n; i++){
            suffixProduct[i] = prefixProd * (i == n - 1 ? 1 : suffixProduct[i + 1]);
            prefixProd *= nums[i];
        }
        return suffixProduct;

    }
};