// Easy - Calculate Money in Leetcode Bank
// https://leetcode.com/problems/calculate-money-in-leetcode-bank/

class Solution {
public:
    // int totalMoney(int n) {
    //     int lastMondayAmount = 0;
    //     int totalMoney = 0;
    //     int currentDayAmount =  0;
    //     for(int day = 0; day < n; day++){
    //         if(day % 7 == 0) {
    //             currentDayAmount = ++lastMondayAmount;
    //         }
    //         else{
    //             currentDayAmount++;
    //         }
    //         totalMoney += currentDayAmount;
    //     }
    //     return totalMoney;
    // }
    
    // Using Math, first week's totalMoney = 28 
    // second week totalMoney = 28 + 7;
    // third week totalMoney = 28 + 7 + 7
    // so on...
    // using sum of AP
    
    int totalMoney(int n) {
        int nWeeks = n / 7;
        int extraDays = n % 7;
        int totalMoney = ((28 * nWeeks) + 7 * ((nWeeks)*(nWeeks - 1))/2);
        if(n % 7) totalMoney += (extraDays) * ((2 * (nWeeks + 1)) + (extraDays - 1))/2;
        return totalMoney; 
    }
};