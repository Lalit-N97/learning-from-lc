/**
Easy - Find the Distance Value Between Two Arrays
https://leetcode.com/problems/find-the-distance-value-between-two-arrays/
Author : LalitN97
**/

class Solution {
public:
    
    /**
    Logic : 
    for each element in arr1 we get two numbers (
    |a1 - a2| = d 
    i.e. a1 - a2 = d  OR a1 - a2' = -d
    Now two numbers are a2 = a1 - d and other a2' = a1 + d
    the range becomes (a2, a2') both exlusive
    ) which is a range in which the elements of arr2 will not fall.
    To find this range in the arr2 we need to sort the second input array arr2. 
    so that we can apply binary search on it.
    This questions boils down to - for each element in arr1 check whether all numbers of arr2 will fall 
    out of the range which we got from above.
    Time Complexity - O(N * logN)
    Space Complexity - O(1)
    **/
    
    // get the first index of the element (from left) which is equal to or greater than key
    int getFirstIdxFromLeft(vector<int> arr, int key){
        int start = 0;
        int end = arr.size() - 1;
        int idx = arr.size();
        while(start <= end){
            int mid = start + (end - start)/2;
            if(arr[mid] >= key){
                idx = mid;
                end = mid - 1;
            }
            else start = mid + 1;
        }
        return idx;
    }
    
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int notInRangeCount = 0;
        for(int ele : arr1){
            int start = ele - d - 1;
            int end = ele + d + 1;
            int idx = getFirstIdxFromLeft(arr2, end);
            if(idx == 0) notInRangeCount++;
            else if(arr2[idx - 1] <= start) notInRangeCount++;
        }
        return notInRangeCount;
    }
};