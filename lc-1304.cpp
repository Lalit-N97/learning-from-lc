/**
Easy - Find N Unique Integers Sum up to Zero
https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/
Author : LalitN97
**/

class Solution {
public:
    
    /**
    Logic : 
    Idea is to imagine a number line with 0 at the mid. try to generate that array of unique elements by adding two
    elements from the number line elemets quidistance from 0 to its left and to its right. Do this by incrementing 
    number by 1. take a start variable which will fill the array such that the first index will contain 0 
    depends on whether n is odd or even. For Even n, we don't need 0 at first index, for odd n we need 0.
    Time Complexity - O(N)
    Space Complexity - O(1)
    **/
    
    vector<int> sumZero(int n) {
        vector<int> unique(n, 0);
        int start = n & 1 ? 1 : 0; 
        while(start < n){
            unique[start] = (start == 0 || start == 1) ? 1 : (unique[start - 2] + 1);
            unique[start + 1] = -1 * (unique[start]);
            start += 2;
        }
        return unique;
    }
};