/**
Medium - Check If a String Can Break Another String
https://leetcode.com/problems/check-if-a-string-can-break-another-string
Written By : LalitN97
**/

class Solution {
public:

    /**
    Idea : store the freqencies of each arrays' element in two different arrays of size 26. Now check if wither of them
    can break each other or not using a single function, by iterating over the frequency arrays using two pointers.
    One pointer will always tried to break other pointer (i.e i >= j) and if it is not able to do so then return false.
    Time Complexity - O(2*N)
    Space Complexity - O(C)
    where N is the size of the input strings 
    and C is a constant C = 26 + 26 + 26 + 26 (4 arrays of size 26)
    **/

    // this function check if a1 can break a2 or not
    bool isBreakable(int* a1, int* a2){
        vector<int> freq1(a1, a1 + 26);
        vector<int> freq2(a2, a2 + 26);
        int i = 0;
        int j = 0;
        while(i < 26 && freq1[i] == 0) i++;
        while(j < 26 && freq2[j] == 0) j++;
        while(i < 26){
            if(i < j) return false;
            int minFreq = min(freq1[i], freq2[j]);
            freq1[i] -= minFreq;
            freq2[j] -= minFreq;
            while(i < 26 && freq1[i] == 0) i++;
            while(j < 26 && freq2[j] == 0) j++;
        }
        return true;
    }

    bool checkIfCanBreak(string s1, string s2) {
        int freq1[26] = {0};
        int freq2[26] = {0};
        for(int i = 0; i < s1.size(); i++) {
            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }
        return isBreakable(freq1, freq2) || isBreakable(freq2, freq1);
    }
};