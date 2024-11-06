// Easy - Check If Two String Arrays are Equivalent

// https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/

class Solution {
public:
    
    /**
    Iterate over the array and append thier elements into a string variable for both arrays. At last compare them and return the answer whether these strings are same or not.
    Time Complexity - O(N)
    Space Complexity - O(N)
    **/
    
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string aStr = "";
        for(int i = 0; i < word1.size(); i++) aStr += word1[i];
        string bStr = "";
        for(int i = 0; i < word2.size(); i++) bStr += word2[i];
        return aStr == bStr;
    }
};