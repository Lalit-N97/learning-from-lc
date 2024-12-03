/**
Medium - Adding Spaces to a String
https://leetcode.com/problems/adding-spaces-to-a-string/
Author : LalitN97
**/


class Solution {
public:
    
    /**
    Idea : 
    Traverse the string and also keep a pointer on spaces vector to track the space index in the string.
    for every character in the string while iterating over it push the string's character into resultant string
    but before that always check for the spaces as per the other pointer and push the space if current index
    becomes equal to the spaces's current index. In this case increment both the ponter.otherwise increment
    only original string's pointer.
    Time Complexity - O(N)
    Space Complexity - O(N)
    where N is the size of original input string
    **/
    
    string addSpaces(string s, vector<int>& spaces) {
        int j = 0;
        int n = s.size();
        string spaciousStr = "";
        for(int i = 0; i < n; i++){
            if(j < spaces.size() && i == spaces[j]){
                j++;
                spaciousStr += " ";
            }
            spaciousStr += s[i];
        }
        return spaciousStr;
    }
};