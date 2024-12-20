/**
Easy - Check if Array Is Sorted and Rotated
https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/
Written By : LalitN97
**/

class Solution {
public:
    
    /**
    Idea : 
    Imagine Every nonDecreasing sorted array in a graph with index at x axis and values at y axis.
    You'll see two straight lines. Later one will have all the values less than or equal to 
    the first element. Apply this concept. Iterate over the array and look for a point where 
    cur element is less than the previoud element. Now continue iterating over the array and check if 
    all the elements are in nonDecreasing order and all the elements are smaller or equal to the first element.
    Time Complexity - O(N)
    Space Complexity - O(1)
    **/
    
    bool check(vector<int>& arr) {
        int n = arr.size();
        if(n < 3) return true;
        int i = 1;
        while(i < n && arr[i] >= arr[i - 1]) i++;
        if(i < n && arr[i] > arr[0]) return false;
        i++;
        while(i < n && arr[i] >= arr[i - 1] && arr[0] >= arr[i]) i++;
        return i >= n;
    }
};