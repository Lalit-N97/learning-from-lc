// https://leetcode.com/problems/find-numbers-with-even-number-of-digits/

/**
Logic : iterate over the array and get the count of digits for each input number
track the count of all those numbers with even count;
Time Complexity - O(N * LogK), Space Complexity - O(1);
where N is the size of the array and K is the max input number in the input array
**/

class Solution {
public:
    
    int getDigits(int inputNum){
        int count = 0;
        while(inputNum){
            count++;
            inputNum /= 10;
        }
        return count;
    }
    
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            int nDigits = getDigits(nums[i]);
            if(!(nDigits & 1)) count++;
        }
        return count;
    }
};