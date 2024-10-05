// https://leetcode.com/problems/permutation-in-string/

class Solution {
public:
    
    /**
    Logic : keep a window of source string length in the target string. Also track the frequency of target window string
        Compare the freq of window string with the source string, if they are matching return true, if not matching let's 
        move your n length window one step right and refresh the target freq array and compare the target freq of the new window 
        with the source freq to see if they mathcing or not. DO this until your entire target string is finished iterating.
        Time Complexity - O(26 * N), Space Complexity - O(26)
    **/
    
    bool checkFrequency(int* sourceFreq, int* targetFreq){
        for(int i = 0; i < 26; i++){
            if(sourceFreq[i] != targetFreq[i]) return false;
        }
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        int sourceFreq[26];
        int targetFreq[26];
        memset(sourceFreq, 0, sizeof sourceFreq);
        memset(targetFreq, 0, sizeof targetFreq);
        int n = s1.size();
        int m = s2.size();
        if(n > m) return false;
        for(int i = 0; i < n; i++) sourceFreq[s1[i] - 'a']++;
        int i = 0;
        while(i < n){
            targetFreq[s2[i] - 'a']++;
            i++;
        }
        
        if(checkFrequency(sourceFreq, targetFreq)) return true;
        
        for(int start = 0, end = n - 1; end < m - 1; start++, end++){
            targetFreq[s2[start] - 'a']--;
            targetFreq[s2[end + 1] - 'a']++;
            if(checkFrequency(sourceFreq, targetFreq)) return true;
        }
        return false;
    }
};