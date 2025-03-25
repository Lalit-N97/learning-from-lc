/**
Medium - Check if Grid can be Cut into Sections
https://leetcode.com/problems/check-if-grid-can-be-cut-into-sections
Written By : LalitN97
**/

class Solution {
public:

    /**
    Idea : sort the 2d matrix in ascending order  based on x axis ranges first and check if there are no overlaps between 
    two adjacent  elements. the the no of noOverlaps >= 2 then we can make two valid vertical cuts. And if you are not 
    able to make veritcal cuts then sort the 2d matrix in ascending order with y axis ranges and similary check for no 
    overlaps to find if valid horizontal cuts can be made or not.
    Time Complexity - O(N * logN)
    Space Complexity - O(1)
    where N is the size of input rectangles matrix
    **/

    static bool xCompare(const vector<int>& A, const vector<int>& B){
        if(A[0] == B[0]) return A[2] < B[2];
        return A[0] < B[0];
    }

    static bool yCompare(const vector<int>& A, const vector<int>& B){ //  compare requires strict weak ordering, replace 
    // <= with < , otherwise program will crash will heap overflow error
        if(A[1] == B[1]) return A[3] < B[3];
        return A[1] < B[1];
    }

    static void print(const vector<vector<int>>& rectangles){
        for(int i = 0; i < rectangles.size(); i++){
            cout << "[" << rectangles[i][0] << "," << rectangles[i][1] << "," << rectangles[i][2] << "," << rectangles[i][3] << "],";
        }
        cout << "\n";
    }

    bool isValidCuts(int n, vector<vector<int>>& rectangles, bool vertical = true){
        int nBreaks = 0;
        int j = vertical ? 0 : 1;
        int maxCurEnd = rectangles[0][j + 2];
        for(int i = 1; i < rectangles.size(); i++){
            int curStart = rectangles[i][j];
            int curEnd = rectangles[i][j + 2];
            if(curStart >= maxCurEnd) nBreaks++;
            maxCurEnd = max(maxCurEnd, curEnd);
            if(nBreaks == 2) return true;
        }
        return false;
    }

    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        sort(rectangles.begin(), rectangles.end(), xCompare);
        bool isValid = isValidCuts(n, rectangles);
        if(!isValid) {
            sort(rectangles.begin(), rectangles.end(), yCompare);
            return isValidCuts(n, rectangles, false);
        }
        return isValid;
    }
};