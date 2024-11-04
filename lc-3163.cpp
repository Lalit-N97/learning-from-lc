Medium - String Compression III

// https://leetcode.com/problems/string-compression-iii/

class Solution {
public:
    
    /**
     
     Logic : 
     Keep a counter while iterating over the string which track the number of consecutive equal characters in the string. If the count of same consecutive characters becomes equal to 9. Append the character into the compressed string and its count, otherwise keep increasing the count. Once the current and prevCharacter are not equal than also append the prevChar count into the compressed string only if the count is greater than 0;
     Time Complexity - O(N)
     Space Complexity - O(N) - for compressed string
     where N is the size of input string
     
    **/   
    
    string compressedString(string word) {
        int n = word.size();
        int count = 1;
        string comp = "";
        for(int i = 1; i < n; i++){
            if(word[i] == word[i - 1]){
                count++;
                if(count == 9){
                    comp += to_string(count) + word[i - 1];
                    count = 0;
                }
            }
            else{
                if(count > 0) comp += to_string(count) + word[i - 1];
                count = 1;
            }
        }
        
        if(count > 0) comp += to_string(count) + word[n - 1];
        
        return comp;
    }
};