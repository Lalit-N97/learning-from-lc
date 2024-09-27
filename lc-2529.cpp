// https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/

class Solution {
public:
    
    // Time Complexity - O(log(N)) and Space Complexity - O(1)
    
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int lastNegativeIdx = -1;
        int start = 0;
        int end = n - 1;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(nums[mid] < 0) {
                lastNegativeIdx = mid;
                start = mid + 1;
            }
            else end = mid - 1;
        }
        start = 0;
        end = n - 1;
        int firstPositiveIdx = n;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(nums[mid] > 0) {
                firstPositiveIdx = mid;
                end = mid - 1;
            }
            else start = mid + 1;
        }
        return max(n - firstPositiveIdx, lastNegativeIdx + 1) ;
    }
};