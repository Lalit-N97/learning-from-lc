/**
Medium - Count Days Without Meetings
https://leetcode.com/problems/count-days-without-meetings
Written By : LalitN97
**/


class Solution {
public:

    /**
    Idea : this problem is based on merge intervals pattern but can be approached with other ways.
    Sort the meetings array in ascending order first with its start date and then with its end date.
    Then iterate over the meetings array to see the difference of adjacent skipped meetings.
    Time Complexity - O(N * LogN)
    Space Complexity - O(1)
    where N is the size of the input meetings array
    **/

    static bool compare(vector<int>& A, vector<int>& B){ // use reference otherwise copying into vectors will result in TLE
        if(A[0] == B[0]) return A[1] <= B[1];
        return A[0] <= B[0];
    }

    int countDays(int days, vector<vector<int>>& meetings) {
        int n = meetings.size();
        sort(meetings.begin(), meetings.end(), compare);
        int i = 0;
        int noMeetingsCount = meetings[i][0] - 1;
        int maxEnd = meetings[i][1];
        i++;
        for(; i < n; i++){
            int start = meetings[i][0];
            int end = meetings[i][1];
            if(start <= days){
                if(maxEnd < start) noMeetingsCount += start - maxEnd - 1;
            }
            else{
                break;
            }
            maxEnd = max(maxEnd, end);
        }
        if(maxEnd < days) noMeetingsCount += days - maxEnd;
        return noMeetingsCount;
    }
};