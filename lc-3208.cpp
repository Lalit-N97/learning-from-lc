/**
Medium - Alternating Groups II
https://leetcode.com/problems/alternating-groups-ii
Written By : LalitN97
**/

class Solution {
public:

    /**
    Idea : iterate over k length subarray to find whehter the subsequenct integers are alternating. This
    could be achieved through sliding window where at first iteration upto k find if the substring is
    valid or not and then move the start and end of the window one step right to slide over the array
    until the start becomes >= n;
    Time Complexity - O(N + K)
    Space Complexity - O(1)
    where N is the size of the input array and K is the window size
    **/

    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int start = 0;
        int end = start;
        int nAlternatingGroups = 0;
        while(start < n){
            if((end - start + 1) == k){
                nAlternatingGroups++;
                while(start < n && colors[end%n] != colors[(end + 1)%n]){
                    start++;
                    end++;
                    if(start < n){
                        nAlternatingGroups++;
                    }
                }
                if(start < n){
                    start = end + 1;
                    end = start;
                }
            }
            else{
                while(end < (start + k - 1) && colors[end%n] != colors[(end + 1)%n]){
                    end++;
                }
                if(end < (start + k - 1)){
                    start = end + 1;
                    end = start;
                }
            }
        }
        return nAlternatingGroups;
    }
};