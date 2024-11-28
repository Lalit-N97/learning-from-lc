/**
Easy - Check If N and Its Double Exist
https://leetcode.com/problems/check-if-n-and-its-double-exist/
Author : LalitN97
**/

class Solution {
public:

    /**
    Logic : 
    Iterate over the array and store the elements into a hashmap (isExist)
    Also keep a counter which count the no of elements which is equal to 0
    if those 0 elements are greater than 1 then you will there is always a solution exist
    in other case iterate over the array and check if the current element's double exist or not using isExist map
    but remeber to handle the case when current element is 0.
    Time Complexity - O(N)
    Space Complexity - O(N)
    **/
    
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, bool> isExist;
        int zeroCount = 0;
        for(int ele : arr) {
            isExist[ele] = true;
            if(ele == 0) zeroCount++;
        }
        if(zeroCount > 1) return true;
        for(int ele : arr){
            if(isExist[ele * 2] && ele != 0) return true;
        }
        return false;
    }
};