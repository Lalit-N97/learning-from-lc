/**
Medium - Count Complete Subarrays in an Array
https://leetcode.com/problems/count-complete-subarrays-in-an-array
Written By : LalitN97
**/

class Solution {
public:

    /**
    Idea : Consider each element as the start of the smallest length valid subarray, then the no of such subarrays with
    starting element is at index i is n - i;
    Sum up no of such valid subarrays for each index in the array, you'll get your answer.
    Approach : 
    Step 1 : find no of distinct elements in the entire subarray using a map . TIme -> O(N) and Space -> O(N)
    Step 2 : keep two pointers start and end such that they iterate over the array in a manner that start will be fixed
    at ith index and end keeps moving until smallest length valid subarray is found and this is again achievalbe using
    a map or frequency array.
    Step 3 : once you find the smallest valid subarray starting with range (l, r) then add n - r in your answer as
    this will be all valid subarrays which starts with start index.
    Step 4 : move the start until you see an invalid subarray( no of distinct elements <> total array distinct elementa)
    Step 5 : repeat the Step 2 until end crosses the last index.
    Time Complexity - O(N)
    Space Complexity - O(N)
    where N is the size of the input array.
    **/

    int countCompleteSubarrays(vector<int>& nums) {
        int nDistinct = 0;
        int freq[2001] = {0};
        for(int num : nums){
            nDistinct += freq[num] == 0;
            freq[num]++;
        }

        memset(freq, 0, sizeof freq);
        
        int start = 0;
        int end = 0;
        int n = nums.size();
        int nValidSubarrays = 0;
        int curDistinct = 0;
        while(end < n){
            freq[nums[end]]++;
            if(freq[nums[end]] == 1) curDistinct++;
            while(curDistinct == nDistinct){
                nValidSubarrays += (n - end);
                freq[nums[start]]--;
                if(freq[nums[start]] == 0) curDistinct--;
                start++;
            }
            end++;
        }
        return nValidSubarrays;
    }
};