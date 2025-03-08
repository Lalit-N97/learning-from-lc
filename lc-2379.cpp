/**
Easy - Minimum Recolors to Get K Consecutive Black Blocks
https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks
Written By : LalitN97
**/

class Solution {
public:

    /**
    Idea : count the no of W's in every k size window and among those numbers minimum no of W's is our answer
    Algorithm : keep a start at 0 and end pointer at kth position  by iterating over the string once and also
    track the no of W's in the window of start and end. Next step is to move both the pointers one step right
    and decrease/increase (change) the no of W's accordingly. Whenver you see a less no of W's in a certain
    window store it in a variable. At the end return that min Variable.
    Time Complexity - O(N)
    Space Complexity - O(1)
    where N is the size of the input string
    **/

    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int start = 0;
        int end = start;
        int wCount = 0;
        while(end < k){
            if(blocks[end] == 'W') wCount++;
            end++;
        }
        int minWCount = wCount;
        while(end < n){
            if(blocks[start] == 'W') wCount--;
            start++;
            if(blocks[end] == 'W') wCount++;
            end++;
            minWCount = min(minWCount, wCount);
        }
        return minWCount;
    }
};