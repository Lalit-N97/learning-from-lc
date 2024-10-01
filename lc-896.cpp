// https://leetcode.com/problems/monotonic-array/

class Solution {
public:
    
    /**
    
    Logic : take boolean variable to determine whether the array is increasing or decreasing using first and last element of the array
    Now iterate over the array and figure out the cases where the elements of the array does not satisfy either increasing or decreasing sequence. 
    for the n = 1 or n = 2 case separately because it will always statisfy the increasing or decreasing sequence.
    Time Complexity : O(N), Space Complecity : O(1)
    
    **/
    
    bool isMonotonic(vector<int>& arr) {
        int n = arr.size();
        if(n < 3) return true;
        bool isIncreasing = false;
        if(arr[0] <= arr[n - 1]) isIncreasing = true;
        for(int i = 1; i < n; i++){
            if(isIncreasing && (arr[i] < arr[i - 1])){
                return false;
            }
            else if((!isIncreasing) && (arr[i] > arr[i - 1])){
                return false;
            }
        }
        return true;
    }
};