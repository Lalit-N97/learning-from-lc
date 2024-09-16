// https://leetcode.com/problems/minimum-time-difference/

/**
Logic : convert each string of hours and minutes to integer hours and minutes
and sort them in ascending order of time
Once sorted find the difference between adjacent times and track min difference
The last time in the begining and the end of sorted times array should be consider as circular path (as in clock)
so difference is taken accordingly.
Time Complexity - O(N * LogN * sizeof(timeString)), Space Complexity - O(1);
**/

class Solution {
public:
    
    bool static compare(string t1, string t2){
        int hours1 = (t1[0] - '0') * 10 + (t1[1] - '0');
        int minutes1 = (t1[3] - '0') * 10 + (t1[4] - '0');
        int hours2 = (t2[0] - '0') * 10 + (t2[1] - '0');
        int minutes2 = (t2[3] - '0') * 10 + (t2[4] - '0');
        if(hours1 == hours2) return minutes1 < minutes2;
        return hours1 < hours2;
    }
    
    void print(vector<string> v){
        for(int i = 0; i < v.size(); i++) cout << v[i] << " ";
        cout << "\n";
    }
    
    int getTimeDifference(string t1, string t2){
        int hours1 = (t1[0] - '0') * 10 + (t1[1] - '0');
        int minutes1 = (t1[3] - '0') * 10 + (t1[4] - '0');
        int hours2 = (t2[0] - '0') * 10 + (t2[1] - '0');
        int minutes2 = (t2[3] - '0') * 10 + (t2[4] - '0');
        return (hours2 - hours1) * 60 + (minutes2 - minutes1);
    }
    
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        sort(timePoints.begin(), timePoints.end(), compare);
        print(timePoints);
        int minTimeDiff = 1500;
        for(int i = 1; i < n; i++){
            minTimeDiff = min(minTimeDiff, getTimeDifference(timePoints[i - 1], timePoints[i]));
        }
        return min(minTimeDiff, getTimeDifference("00:00", timePoints[0]) + getTimeDifference(timePoints[n - 1], "24:00"));
    }
};