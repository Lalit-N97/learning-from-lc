// Easy - Sign of the Product of an Array
// https://leetcode.com/problems/sign-of-the-product-of-an-array/

class Solution {
public:
    
    /**
    Logic : 
    Count the number of negative numbers in the input array.
    While counting if you encounter a zero than resultant product will be 0 and we can return 0.
    If the no of negative numbers are odd then resultant product will be negative otherwise the product will 
    be positive.
    Time Complexity - O(N)
    Space Complexity - O(1)
    where N is the input array size.
    **/
    
    int arraySign(vector<int>& nums) {
        int nNegatives = 0;
        for(int ele : nums){
            if(ele == 0) return 0;
            else if(ele < 0) nNegatives++;
        }
        return (nNegatives & 1) ? -1 : 1;
    }
};