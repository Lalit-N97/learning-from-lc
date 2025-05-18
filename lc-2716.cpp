/**
Easy - Minimize String Length
https://leetcode.com/problems/minimize-string-length
Written By : LalitN97
**/

class Solution {
public:

    /**
    Idea : store and count the existance of each distinct character in the string, this will be our answer.
    Approach using bitmasking : use an integer variable which can store upto 32 bits where each bits are wither 0 or 1.
    0 represents the character is not present and 1 represents the character is present. Since our constraints says that
    we have given lowercase english alphabet which ranges from 0 to 26 distinct characters. These characters existance can 
    be stored in a 32 bit integer number.
    Iterate over the string and build the 32 bit integer variable (which is intially intialised to 0) by setting its bit to 1 
    for the character position.
    e.g. 000101 represents c and a are present in the string.
         010010 represents e and b are present in the string.
         so every bit upto 26 bits from end represents the existance of letters a to z.
    In the end we need to calculate the no of set bits of that 32 bit integer number.
    Time Complexity - O(N)
    Space Complexity - O(1)
    where N is the size of input string.
    **/

    int minimizedStringLength(string s) {
        int existBits = 0;
        for(char ch : s) existBits |= 1 << (ch - 'a');

        // now count the no of set bits in existBits;
        int count = 0;
        while(existBits){
            existBits = existBits & (existBits - 1);
            count++;
        }
        return count;
    }
};