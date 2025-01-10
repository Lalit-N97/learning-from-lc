/**
Easy - Minimum Time to Type Word Using Special Typewriter
https://leetcode.com/problems/minimum-time-to-type-word-using-special-typewriter/description/
Written By : LalitN97
**/

class Solution {
public:

    /**
    Idea : use modulus to obtain characters upto 26 letters 
    anticlockwise rotation looks like moving from cur character to previous character i.e. c - prev + 26
    clockwise rotaions looks like moving from cur character to next character i.e  next - c + 26
    minimum of these % 26 will give us the minSeconds to reach there in a circular path and printing the same
    character require 1 sec.
    Time Complexity - O(N)
    Space Complexity - O(1)
    where N is the size of the word
    **/

    int minTimeToType(string word) {
        int minSeconds = 0;
        int pointer = 0;
        for(char ch : word){
            int c = ch - 'a';
            minSeconds += min((c - pointer + 26)%26, (pointer - c + 26)%26) + 1;
            pointer = c;
        }
        return minSeconds;
    }
};