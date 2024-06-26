// https://leetcode.com/problems/contains-duplicate/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        // using sorting : Time - O(N*log(N)), Space - O(1)
        // sort(nums.begin(), nums.end());
        // for(int i = 1; i < n; i++){
        //     if(nums[i] == nums[i - 1]) return true;
        // }
        // return false;
        
        // using unordered map : Time - O(N), Space - O(N)
        unordered_map<int, int> freq;
        for(int i = 0; i < n; i++){
            freq[nums[i]]++;
            if(freq[nums[i]] > 1) return true;
        }
        return false;
    }
};