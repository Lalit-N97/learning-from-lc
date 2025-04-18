/**
Medium - Count and Say
https://leetcode.com/problems/count-and-say
Written By : LalitN97
**/

class Solution {
public:

    /**
    Idea : use the function - given a string return its RLE string, for each number from 1 to n build from bottom
    Time Complexity - O(2^N)
    Space Complexity - O(N)
    where N is the max size of the string.
    **/

    string getRLE(string s){
        string ans = "";
        int count = 1;
        char prev = s[0];
        for(int i = 1; i < s.size(); i++){
            char cur = s[i];
            if(prev != cur){
                ans += to_string(count) + prev;
                prev = cur;
                count = 1;
            }
            else count++;
        }
        ans += to_string(count) + prev;
        return ans;
    }

    string countAndSay(int n) {
        string ans = "1";
        for(int i = 1; i < n; i++) ans = getRLE(ans);
        return ans;
    }
};