/**
Medium - Decode XORed Permutation
https://leetcode.com/problems/decode-xored-permutation
Written By : LalitN97
**/

class Solution {
public:

    /**
    Idea : detemining the first element can decode the entire array in linear time. Figuring out first element using
    Brute force will require every element from 1 to n to consider as first element and try to build the decoded array,
    which will take quadratic time. We can use the condition that n is odd as below
    Since n is odd. the encoded array looks like this {a1^a2, a2^a3, a3^a4, a4^a5, a5^a6, ...}
    Suppose n = 5 and E = {a1^a2, a2^a3, a3^a4, a4^a5}. here the last encoded element will always has odd element a5 in
    the end in the same order.
    which helps us restructure it as a1 ^ (a2^a3) ^ (a4^a5). This is the xor of all elements. Let's say it x.
    Since all elements are the permutation from 1 to n, so finding out n will be easy in linear time.
    First element can be find out using : 
    a1 = x ^ E[1] ^ E[3] ^ E[5] ... i.e. Xor of all elements xored with xor of elements present at odd indices of encoded
    Time Complexity - O(N)
    Space Complexity - O(1)
    **/

    vector<int> decode(vector<int>& encoded) {
        int n = encoded.size();
        int allXor = 0;
        int oddIndicesXor = 0;
        for(int i = 0; i < n; i++){
            allXor ^= (i + 1);
            oddIndicesXor ^= (i & 1) ? encoded[i] : 0;
        }
        allXor ^= (n + 1); // xoring last element n from permutation array.

        int curEle = allXor ^ oddIndicesXor;
        int prevXor = 0;
        for(int i = 0; i < n; i++){
            prevXor = encoded[i];
            encoded[i] = curEle; 
            curEle ^= prevXor;
        }
        encoded.push_back(curEle);
        return encoded;
    }
};