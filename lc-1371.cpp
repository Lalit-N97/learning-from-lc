// https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/

class Solution {
public:
    
    /**
    void print(int *arr, int n){
        for(int i = 0; i < n; i++) cout << arr[i] << " ";
        cout << "\n";
    }
    
    bool isOddFreqVovels(int vovelFreq[26]){
        for(int i = 0; i < 26; i++){
            if(vovelFreq[i] & 1) return true;
        }
        return false;
    }
    
    bool isVovel(char c){
        return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u'; 
    }
    
    // Logic : brute force recursion
    // Time Complexity - O(2^N), Space Complexity - O(N) -> not a feasible solution
    // using DP : TIme Complexity - O(N*N), Space Complexity - O(N*N) -> still not a feasible solution
    int len(string s, int start, int end, int* vovelFreq){
        if(start > end) return 0;
        if(start == end && isVovel(s[start])) return 0;
        // print(vovelFreq, 26);
        if(!isOddFreqVovels(vovelFreq)) return end - start + 1;
        int leftMax = 0;
        int rightMax = 0;
        if(isVovel(s[end])){
            vovelFreq[s[end] - 'a']--;
            leftMax = len(s, start, end - 1, vovelFreq);
            vovelFreq[s[end] - 'a']++;
        }
        else leftMax = len(s, start, end - 1, vovelFreq);
        if(isVovel(s[start])){
            vovelFreq[s[start] - 'a']--;
            rightMax = len(s, start + 1, end, vovelFreq);
            vovelFreq[s[start] - 'a']++;
        }
        else rightMax = len(s, start + 1, end, vovelFreq);
        return max(leftMax, rightMax);
    }
    
    int findTheLongestSubstring(string s) {
        int vovelFreq[26] = {0};
        memset(vovelFreq, 0, sizeof vovelFreq);
        
        for(char c : s){
            if(isVovel(c)){
                vovelFreq[c - 'a']++;
            }
        }
        
        return len(s, 0, s.size() - 1, vovelFreq);
        
    }
    **/
    
    
    /** solved using discussion 
    
    Logic : problem kind of subarray with longest sum using prefix sum array 
    1. create a simulation of prefix array (where the array elements store whether at a point in stirng the all vowels are even or odd)
    1. iterate over the string and keep track of odd and even vowels using bitmasking, change the parity or flip the bit whenever you see a vowel.
    2. just like prefix sum subarray problem, to find the longest string of even vowels, at each point in string you have to see whether the bitmask appears already before (for the first time) - if yes, then consider our potential answer as the length of that subtring from first time bitmask index upto current point in string.
    3. Do the step 3 at each iteration, you will surely get the maximum substring with even no of vowels.
    
    **/
    int findTheLongestSubstring(string s) {
        // stores mask number as key and first index(in the array) of that mask number as value
        unordered_map<int, int> idx;
        idx[0] = -1;
        int mask = 0;
        int maxLen = 0;
        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            if(c == 'a') mask = mask ^ (1);
            if(c == 'e') mask = mask ^ (1 << 1);
            if(c == 'i') mask = mask ^ (1 << 2);
            if(c == 'o') mask = mask ^ (1 << 3);
            if(c == 'u') mask = mask ^ (1 << 4);
            
            // if you see the mask number for the first time then store the mask number in the map with its index in the string
            if(idx.find(mask) == idx.end()){
                idx[mask] = i;
            }
            else{
                maxLen = max(maxLen, i - idx[mask]);
            }
        }
        return maxLen;
    }
    
};