// Medium - Count the Number of Fair Pairs
// https://leetcode.com/problems/count-the-number-of-fair-pairs/

class Solution {
public:
    
    /**
    Logic :
    Idea is to find the suitable min and max element for each element as per the range (lower, upper) in a aorted collections of elements and then count each elements suitable pairs.
    So first sort the input array nums
    for each elemented in the sorted array find the index (say minIdx) in the array such that the sum of current element and the elements at that index will give lower i.e. since you know the lower value, find the index of the element for which lower value - current value is found in the array using binary search.
    Similarly find the index (say maxIdx) for upper value.
    For each element find their minIdx and maxIdx and determine the count of the range of elements because the range (minIdx, maxIdx) will form suitable pairs with the current element.
    Sum of all those count for each element in the array will be our answer.
    Time Complexity - O(N * logN)
    Space Complexity - O(1)
    **/
    
    // binary search
    int getIdxForLower(vector<int>& nums, int key, int start){
        int end = nums.size() - 1;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(nums[mid] < key) start = mid + 1;
            else end = mid - 1;
        }
        return start - 1;
    }
    
    int getIdxForUpper(vector<int>& nums, int key, int start){
        int end = nums.size() - 1;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(nums[mid] <= key) start = mid + 1;
            else end = mid - 1;
        }
        return end;
    }
    
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long count = 0;
        for(int i = 0; i < n; i++){
            long long minIdx = getIdxForLower(nums, lower - nums[i], i + 1);
            long long maxIdx = getIdxForUpper(nums, upper - nums[i], i + 1);
            count += (maxIdx - minIdx);
        }
        return count;
    }
};  