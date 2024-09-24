// https://leetcode.com/problems/rotate-string/

class Solution {
public:
    
    // Naive string matching algorithm
    // Time Complexity - O(N^2) and Space Complexity - O(1)
    
    bool isMatch(string inp, string goal, int start){
        int n = inp.size();
        int m = goal.size();
        if(m != n) return false;
        int i = 0;
        while(i < n){
            int idx = (i + start) % n;
            if(inp[idx] != goal[i]) return false;
            i++;
        }
        return true;
    }
    
    bool rotateString(string s, string goal) { 
        for(int start = 0; start < s.size(); start++){
            if(isMatch(s, goal, start)) return true;
        }
        return false;
    }
};