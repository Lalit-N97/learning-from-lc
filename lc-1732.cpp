// Easy - Find the Highest Altitude

// https://leetcode.com/problems/find-the-highest-altitude/

class Solution {
public:
    
    /**
    
    Logic : 
    Every element of the array represents the gain in altitude (negative & positive).
    So current altitude can be fetched by summing up the gain to the current altitude.
    Time Complexity - O(N)
    Space Complexity - O(1)
    where N is the size of the input array
    
    **/
    
    int largestAltitude(vector<int>& gain) {
        int highestAltitude = 0;
        int currentAltitude = 0;
        for(int i = 0; i < gain.size(); i++){
            currentAltitude += gain[i];
            highestAltitude = max(highestAltitude, currentAltitude);
        }
        return highestAltitude;
    }
};