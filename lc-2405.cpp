/**
Medium - Optimal Partition of String
https://leetcode.com/problems/optimal-partition-of-string
Written By : LalitN97
**/


class Solution {
public:

    /**
    Idea : we need to track the small case letters existance in a string for the current partition.
    This can be achieved via bitmasking.
    Time Complexity - O(N)
    Space Complexity - O(1)
    where N is the size of input string
    **/

    int partitionString(string s) {
        int isExist = 0; // using bits to see if any character is already present while iterating through 
        // a partition
        int nPartitions = 1;
        for(char ch : s){
            int setBit = 1 << (ch - 'a');
            if(isExist & setBit){
                nPartitions++;
                isExist = 0; // reset the existance of the characters as we are going to traverse a new partition
            }
            isExist |= setBit;
        }
        return nPartitions;
    }
};