// https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/

class Solution {
public:
    
    /**
    Logic : to have equal sum between 2 player teams, we will be needing to find the targetSum (i.e. first element + last element) in a sorted sequence. taking other 2 element combination sum will not be possible.
    Once you find the min element + max element sum as target sum. constitute two player team using two pointers one starting from beginning of the array and other starting from the end of the array.
    Time Complexity - O(NlogN), Space Complexity - O(1)
    This can be achieved using map or freq array also. Figure it out! - Time Complexity - O(N), Space Complexity - O(N)
    **/
    
    long long dividePlayers(vector<int>& skill) {
        // sorting approach :
        // int n = skill.size();
        // sort(skill.begin(), skill.end());
        // int target = skill[0] + skill[n - 1];
        // long long ans = 0;
        // for(int i = 0; i < n/2; i++){
        //     int teamSum = skill[i] + skill[n - 1 - i];
        //     long long teamProduct = skill[i] * skill[n - 1 - i];
        //     if(target == teamSum) ans += (long long)teamProduct;
        //     else return -1;
        // }
        // return ans;
        
        
        // freq array approach : 
        int n = skill.size();
        int minm = INT_MAX;
        int maxm = INT_MIN;
        int freq[1001];
        memset(freq, 0, sizeof freq);
        for(int i = 0; i < n; i++){
            minm = min(minm, skill[i]);
            maxm = max(maxm, skill[i]);
            freq[skill[i]]++;
        }
        int target = minm + maxm;
        long long chemistry = 0;
        int start = minm;
        int end = maxm;
        while(start <= end){
            if(freq[start] > 0 && freq[end] > 0){
                int teamSum = start + end;
                long long teamProduct = start * end;
                freq[start]--;
                freq[end]--;
                if(target == teamSum) chemistry += (long long)teamProduct;
                else return -1;
            }
            else if(freq[start] != 0) end--;
            else if(freq[end] != 0) start++;
            else {
                start++;
                end--;
            }
        }
        return chemistry;
        
    }
};