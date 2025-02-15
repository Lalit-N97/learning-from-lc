/**
Medium - Sort Vowels in a String
https://leetcode.com/problems/sort-vowels-in-a-string
Written By : LalitN97
**/

class Solution {

/**
Idea : to find whether a char is a vovel or not you can use switch case in a different function.
Take a int frequency map which will store the frequency of occurence of vovels inside input string.
Now iterate over the string to replace the vovels based as per the position of vovels in the frequency array.
Time Complexity - O(N)
Space Complexity - O(C)
where N is the size of input string
and C is a constant where C = 60
**/

public:

    bool isVovel(char ch){
        switch(ch){
            case 'A':
            return true;
            case 'E':
            return true;
            case 'I':
            return true;
            case 'O':
            return true;
            case 'U':
            return true;
            case 'a':
            return true;
            case 'e':
            return true;
            case 'i':
            return true;
            case 'o':
            return true;
            case 'u':
            return true;
            default :
            return false;
        }
        return false;
    }

    string sortVowels(string s) {
        int freq[60];
        memset(freq, 0, sizeof freq);
        for(char ch : s){
            if(isVovel(ch)) freq[ch - 'A']++;
        }
        int ptr = 0;
        for(int i = 0; i < s.size(); i++){
            if(isVovel(s[i])){
                while(ptr < 60 && freq[ptr] == 0) ptr++;
                s[i] = 'A' + ptr;
                freq[ptr]--;
            }
        }
        return s;
    }
};