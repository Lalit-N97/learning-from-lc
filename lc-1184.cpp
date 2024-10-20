// https://leetcode.com/problems/distance-between-bus-stops/

class Solution {
public:
    
    /**
    Logic : iterate over the distance array in clockwise direction and get the clockWiseDistance
    to get the antiClockwiseDirection you can either iterate in anticlockwise direction from source to destination OR what else you can do is to iterate over the distance array from destination to source in clockWiseDirection
    Time Complexity - O(N) , Space Complexity - O(1);
    where N is the number of bus stops distances.
    **/
    
    /**
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int n = distance.size();
        int clockwiseDistance = 0;
        int antiClockwiseDistance = 0;
        // move clockwise from source to destination for clockwiseDistance exluding the destination distance
        for(int i = start; i != destination; i = (i + 1)%n){
            clockwiseDistance += distance[i];
        }
        
        // move again clockwise but this time from destination to source because we have to excluse the source distance to get antiClockwiseDistance
        for(int i = destination; i != start; i = (i + 1)%n){
            antiClockwiseDistance += distance[i];
        }
        return min(clockwiseDistance, antiClockwiseDistance);
    }
    **/
    
    /**
    Logic : One pass solution could be you can iterate over the distance array in clockwiseDirection 
    to get the clockwiseDistance and anitclockWise distance can be found by subtracting anticlockWiseDistance from totalDistance.
    Time Complexity - O(N), Space Complexity - O(1)
    
    **/
    
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int n = distance.size();
        int clockwiseDistance = 0;
        int antiClockwiseDistance = 0;
        int totalDistance = 0;
        if(start > destination) swap(start, destination);
        // move clockwise from source to destination for clockwiseDistance exluding the destination distance
        for(int i = 0; i < n; i++){
            totalDistance += distance[i];
            if(i >= start && i < destination) clockwiseDistance += distance[i];
        }
        antiClockwiseDistance = totalDistance - clockwiseDistance;
        return min(clockwiseDistance, antiClockwiseDistance);
    }
    
};