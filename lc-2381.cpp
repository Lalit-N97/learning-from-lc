/**
Medium - Shifting Letters II
https://leetcode.com/problems/shifting-letters-ii/description/
Written By : LalitN97
**/

class Solution {
public:

    /**
    Idea : (Line Sweep is the name of the idea - name learnt from Discussion)
     process the 2D array shifts such that you will get a total no of forward/backward movements at 
    each index of the string. This processing will use a trick (to reduce the time complexity).
    this trick includes concept of - updating the first and last  1 index of the range and at the end 
    calculate the prefix sum to know how many index has a forward/backward net movement.
    Time Complexity - O(N + M)
    Space Complexity - O(N + 1)
    where N is the size of the input string
    M is the size of shifts 2D array
    **/

    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        int movement[50002];
        memset(movement, 0, sizeof movement);
        // process the shifts queries
        for(vector<int> shift : shifts){
            int leftIdx = shift[0];
            int rightIdx = shift[1] + 1;
            int direction = shift[2] == 0 ? -1 : 1;
            movement[leftIdx] += direction;
            movement[rightIdx] += (-1 * direction);
        }

        // to calculate the commulative movements at each index we have to prefix sum
        for(int i = 1; i < n; i++){
            movement[i] += movement[i - 1];
        }

        // iterate over the string and modify its characters with net movement
        string ans = "";
        for(int i = 0; i < n; i++){
            int netMovement = (s[i] - 'a' + movement[i]) % 26;
            if(movement[i] < 0){
                netMovement = (s[i] - 'a' + (-1 * (abs(movement[i]) % 26))) % 26;
            }
            s[i] = 'a' + (26 + netMovement)%26;
        }
        return s;
    }
};