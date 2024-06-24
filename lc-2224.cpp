
// https://leetcode.com/problems/minimum-number-of-operations-to-convert-time/

class Solution {
public:
    
    int getMinutesDiff(string a, string b){
      return ( ((b[0]- '0') * 10 + (b[1] - '0') - (a[0] - '0') * 10 - (a[1] - '0')) * 60 ) + 
          (b[3]- '0') * 10 + (b[4] - '0') - (a[3] - '0') * 10 - (a[4] - '0');
    }
    
    int convertTime(string current, string correct) {
        int minutes = getMinutesDiff(current, correct);
        int time[4] = {60, 15, 5, 1};
        int nOperations = 0;
        for(int i = 0; i < 4; i++){
            while(time[i] <= minutes){
                minutes -= time[i];
                nOperations++;
            }
        }
        return nOperations;
    }
};