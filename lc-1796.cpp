// Easy - Second Largest Digit in a String
// https://leetcode.com/problems/second-largest-digit-in-a-string/

class Solution {
public:
    
    /**
    Logic : 
    Iterate over the string and track only the elements which are digits in the string.
    Track these digits in an array hashmap of size 10. 
    Once this hashmap is populated after completed traversing the string
    We can iterate over the hashmap from the end to get 2nd largest digit present in the freq map
    Time Complexity - O(N)
    Space Compexiyt - O(m) 
    where N is the size of the input string
    and m is the constant space of 10 digits
    **/
    
    int secondHighest(string s) {
        int freq[10] = {0};
        memset(freq, 0, sizeof freq);
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(s[i] >= '0' && s[i] <= '9'){
                freq[s[i] - '0']++;
            }
        }
        
        int firstTime = -1;
        for(int i = 9; i >= 0; i--){
            if(freq[i] > 0 && (firstTime == -1)) firstTime = i;
            else if(freq[i] > 0) return i;
        }
        return -1;
    }
};