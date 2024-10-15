// https://leetcode.com/problems/separate-black-and-white-balls/

class Solution {
public:
    
    /**
    Logic : use two pointers and keep those pointers in the starting (index 0) of the string.
    one pointer keeps the track of having 0s from the start of the string
    and another pointer will iterate over the string and whenever we see a '0' character we'll compute and add the minimum swaps required to move that '0' character in the end of the list where some 0s are already arranged from begining (one of the pointer is keeping this track)
    Time Complexity - O(N), Space Complexity - O(1)
    where N -> length of the string of characters
    **/
    
    long long minimumSteps(string s) {
        int n = s.size();
        int start = 0;
        int end = 0;
        long long nSwaps = 0;
        while(end < n){
            if(s[end] == '0'){
                nSwaps += (end - start);
                start++;
            }
            end++;
        }
        return nSwaps;
    }
};