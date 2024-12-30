/**
Easy - Check if the Sentence Is Pangram
https://leetcode.com/problems/check-if-the-sentence-is-pangram/description/
Written By : LalitN97
**/

class Solution {
public:

    /**
    Idea : Can be solvable using hashmap with 26 characters
    But also can be solvable by using 26 bits. Iterate over the string to set bits one by one
    then keep a mask of 26 set bits and perform bitwise and with it so see if the resultant number 
    becomes equal to the mask. 
    **/

    bool checkIfPangram(string sentence) {
        int mask = (1 << 26) - 1;
        int ans = 0;
        for(char ch : sentence){
            ans |= (1 << (ch - 'a'));
        }
        return ans == mask;
    }
};