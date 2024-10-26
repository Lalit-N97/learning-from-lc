// https://leetcode.com/problems/three-consecutive-odds/

class Solution {
public:
    
    /**
    Logic : 
    Let's iterate over the array elements, whenever encounter an odd number count its no of consecutive occurences
    , while iterating, if found an even number then reset its count to 0.
    Using this way you once you will reach a consecutive odd count of 3 you can return true from within iterating over the array.
    In the end after finishing iterating over the array check for the count, because it may the last odd element in the array which makes up the count to 3.
    Time Complexity - O(N), Space Complexity - O(1)
    where N is the size of the array.
    **/
    
    bool threeConsecutiveOdds(vector<int>& arr) {
        int countConsecutiveOdds = 0;
        for(int i = 0; i < arr.size(); i++){
            if(countConsecutiveOdds == 3) return true;
            if(arr[i] & 1) countConsecutiveOdds++;
            else countConsecutiveOdds = 0;
        }
        return countConsecutiveOdds == 3;
    }
};