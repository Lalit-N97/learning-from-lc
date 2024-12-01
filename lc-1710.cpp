/**
Easy - Maximum Units on a Truck
https://leetcode.com/problems/maximum-units-on-a-truck/
Author : LalitN97
**/

class Solution {
public:
    
    /**
    Logic : 
    problem is asking on the maximum units a truck can hold based on the maximum boxes it can hold.
    so we need to sort the items of input array in terms of no of units, we need to choose the maximum units per box first
    then choose the later smaller units boxes in descending order, while filling our truck.
    Time Complexity - O(N * logN)
    Space Complexity - O(1)
    where N is the size of input array.
    
    OR 
    
    Other way to the same is to keep a storage which will store no of units(as array index) and no of boxes(as array
    element) together this will take n = 1000 storage space. Then we can iterate over the storage array in reverse order
    and fill our truck with the number of boxes.
    If you get same no of units but different no of boxes then add those no of boxes to store them in the same units index.
    Time Complexity - O(N)
    Space Compexity - O(N)
    
    **/
    
    static bool compare(vector<int> A, vector<int> B){
        if(A[1] == B[1]) return A[0] > B[0];
        return A[1] > B[1];
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        // sort(boxTypes.begin(), boxTypes.end(), compare);
        // int maxUnits = 0;
        // int n = boxTypes.size();
        // for(vector<int> boxes : boxTypes){
        //     if(truckSize >= boxes[0]) {
        //         maxUnits += (boxes[0] * boxes[1]);
        //         truckSize -= boxes[0];
        //     }
        //     else{
        //         maxUnits += (truckSize * boxes[1]);
        //         truckSize = 0;
        //     }
        // }
        // return maxUnits;
        
        int boxes[1001] = {0}; // holds the information of units as index and no of boxes as elements on that index
        memset(boxes, 0, sizeof boxes);
        for(vector<int> boxType : boxTypes){
            int nBoxes = boxType[0];
            int nUnits = boxType[1];
            boxes[nUnits] += nBoxes;
        }
        
        int maxUnits = 0;
        for(int i = 1000; i > 0; i--){
            if(truckSize > 0) maxUnits += (min(boxes[i], truckSize) * i);
            truckSize -= boxes[i];
        }
        return maxUnits;
    }
};