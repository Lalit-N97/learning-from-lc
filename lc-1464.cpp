// https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/

class Solution {
public:
    
    /**
    Logic : Since array size will be atleast two elements consider 1st element as max and secondEle as second max
    if the opposite is true swap the indexes. Then iterate over the array to find if the cur elemnent of the array is greater than the maxIdx's element if yes, update the maxIdx otherwise check if the cur element is greater than secondMax index, if yes update the second max Idx do this until the entire array is fully iterated.
    Time Complexity - O(N), Space Complexity - O(1)
    where N is the size of the input array.
    **/
    
    int maxProduct(vector<int>& nums) {
        int maxIdx = 0;
        int secondMaxIdx = 1;
        if(nums[maxIdx] < nums[secondMaxIdx]) swap(maxIdx, secondMaxIdx);
        for(int i = 2; i < nums.size(); i++){
            if(nums[i] >= nums[maxIdx]){
                secondMaxIdx = maxIdx;
                maxIdx = i;
            }
            else if(nums[i] >= nums[secondMaxIdx]){
                secondMaxIdx = i;
            }
        }
        return (nums[maxIdx] - 1) * (nums[secondMaxIdx] - 1);
    }
};