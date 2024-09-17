//https://leetcode.com/problems/generate-binary-strings-without-adjacent-zeros/

/**

Logic : Pick and not pick the binary characters 0 and 1 based on the last element picked
if the last picked element was 1 then next element can be any of the 0 or 1
if the last picked element was 0 then next element will be 1 only (to avoid adjacent zeros)
frame this in recursive funcation call.
Time Complexity - O(2^N), Space Complexity - O(N) where N is the height/depth of the recursion tree formed.
    
    **/

class Solution {
public:
    
    void buildValidSubstr(string s, vector<string>& ans, int n){
        int m = s.size();
        if(m == n) {
            ans.push_back(s);
            return;
        }
        if(m == 0 || s[m - 1] == '1') buildValidSubstr(s + "0", ans, n);
        buildValidSubstr(s + "1", ans, n);
    }
    
    vector<string> validStrings(int n) {
        vector<string> ans;
        ans.reserve(300000);
        buildValidSubstr("", ans, n);
        return ans;
    }
};