/**
Medium - Bitwise XOR of All Pairings
https://leetcode.com/problems/bitwise-xor-of-all-pairings/description/
Written By : LalitN97
**/

class Solution {
public:

    /**
    Idea : suppose num1 = [a1, a2, a3, ... , an] and num2 = [b1, b2, b3,..., am]
    taking all pairwise xor between these two and then taking the resultant xor pairs xor will be euivalent to 
    taking xor of each element in num1 with itself m times and taking xor of each element in num2 with 
    itself n times.
    Also note if we are taking the xor of an elements with iself even times then result is 0, otherise in case 
    of odd times xor the result is the same element.
    So the problem boils down to xor all the elements of num1 (if the num2 size is odd) + xor of all the 
    elements of num2 (if num1 size is odd), if num1's size is even then num2's elements will not contribute
    in the resultant xor and vice-versa
    **/

    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int resultantXor = 0;
        int n = nums1.size();
        int m = nums2.size();
        if(!(n & 1) && !(m & 1)) return resultantXor;
        if(n & 1){
            for(int num2 : nums2) resultantXor ^= num2;
        }
        if(m & 1){
            for(int num1 : nums1) resultantXor ^= num1;
        }
        return resultantXor;
    }
};