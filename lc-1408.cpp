/**
Easy - String Matching in an Array
https://leetcode.com/problems/string-matching-in-an-array/description/
Written By : LalitN97
**/

class Solution {
public:

    /**
    Idea : Brute Force : for each word iterate over the entire string array except that word and 
    check if that string is present as a substring in other string.
    Match of string is implemented using naive approach of stirng matching
    Time Complexity - O(N * N * S * S)
    Space Complexity - O(N)
    where N is the size of input words array
    and S is the size of each word string
    **/

    bool isFound(string source, string target){
        int n = source.size();
        int m = target.size();
        if(n >= m) return false;
        int i = 0, j = 0;
        while(i < n && j < m){
            while(i < n && j < m && (source[i] == target[j])){
                i++;
                j++;
            }
            if(i == n) return true;
            if(j == m) return false;
            j = j - i + 1;
            i = 0;
        }
        return false;
    }

    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        vector<string> ans;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i != j){
                    if(isFound(words[i], words[j])){
                        ans.push_back(words[i]);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};