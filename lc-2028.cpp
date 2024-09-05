// https://leetcode.com/problems/find-missing-observations/


/**
Need the mean calculation formulae
intially keep the answer array of size n to be all 6 dice number
starting from 1st element make the dice number smaller between range [1, 6]
to make the current sum of n elements reach to the required sum.
Time Complexity - O(N + M), Space Complexity - O(N) - for creating a vector to be retuned
**/

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sumM = 0;
        int m = rolls.size();
        for(int i = 0; i < m; i++) sumM += rolls[i];
        
        // calculate the sum of n missing terms using mean formulae mean = sumOfTerms/noOfTerms;
        int sumN = ((mean) * (n + m)) - sumM;
        
        vector<int> ans;
        ans.reserve(n + 1); // making the capacity as n so that the vector will not resize(doubles)[as this operation takes linear time] itself once capacity becomes full
        
        // find a combination of n outcomes which sums to sumN
        // we know that each outcome domain is [1, 6] so the sum will fall in the range [1*n, 6*n]
        if((sumN < n) || (sumN > (6*n))) return ans;
        
        // now if the sum falls in the valid ans range, then aswer will always possible between [1*n, 6*n]
        // to calculate the combination of such elements, consider all the n missing elements as 6
        // which sums to 6*n sum. Now one by one reduce the elements number to reach to the calculated sum.
        // other way to reduce the sum is to convert 6 to 1 for the elements and track the sum if we are able to reach the required sum (using the difference between requiredSum and the current sum)
        int curSum = 6 * n;
        int reqSum = sumN;
        int diff = curSum - reqSum;
        int nOnes = diff / 5;
        int nextRemainingEle = 6 - (diff % 5);
        int k = 0;
        while(k < nOnes){
            ans.push_back(1);
            k++;
        }
        if(k < n){
            ans.push_back(nextRemainingEle);
            k++;
        }
        while(k < n){
            ans.push_back(6);
            k++;
        }
        return ans;
    }
};