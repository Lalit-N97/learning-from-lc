/**
Medium - Max Sum of a Pair With Equal Sum of Digits
https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits
Written By : LalitN97
**/

class Solution {
public:

    /**
    Idea : traverse over the input numbers and at each element take the sum of the digits. You should take a map
    of <int, set<int>> where for each sum of digits you should store the corresponding elements mapped to it.
    Now once the input array is processed in such a way then iterate over the map and check for each sum of digits,
    if there are more than 1 elements attached in the set and take the sum of the max and second max element.
    Time Complexity - O(N * LogN)
    Space Complexity - O(N)
    where N is the size of input array
    **/

    int sumOfDigits(int num){
        int digitSum = 0;
        while(num){
            digitSum += num%10;
            num /= 10;
        }
        return digitSum;
    }

    int maximumSum(vector<int>& nums) {
        // unordered_map<int, multiset<int>> digitSumMap;
        // for(int num : nums){
        //     int digitSum = sumOfDigits(num);
        //     digitSumMap[digitSum].insert(num);
        // }

        // int maxSum = -1;
        // for(auto p : digitSumMap){
        //     multiset<int> ms = p.second;
        //     if(ms.size() > 1){
        //         multiset<int> :: reverse_iterator rit = ms.rbegin();
        //         int firstMax = *rit; rit++;
        //         int secondMax = *rit;
        //         maxSum = max(maxSum, firstMax + secondMax);
        //     }
        // }
        // return maxSum;

        /**
        New approach : 
        store the elements sum in an array and corresponding to that sum just keep track of only two elements
        firstMax and secondMax.
        On iterating the elements of the input array, for each digitSum, whenever you see the a new element
        store it in the right place as firstMax and secondMax for that corresponding digitSum.
        Time Complexity - O(N)
        Space Complexity - O(C)
        where N is size of input array and C is some constant i.e. C < 200
        */

        pair<int, int> digitSumMap[90]; // since, as per the constraints, the max digit sum we can get is 9*9=81.
        for(int i = 0; i < 90; i++) digitSumMap[i] = {-1, -1};
        for(int x : nums){
            int digitSum = sumOfDigits(x);
            pair<int, int> p = digitSumMap[digitSum];
            int firstMax = p.first;
            int secondMax = p.second;
            if(x >= firstMax) {
                secondMax = firstMax;
                firstMax = x;
            }
            else if(x < firstMax && x > secondMax) secondMax = x;
            digitSumMap[digitSum] = make_pair(firstMax, secondMax);
        }

        int maxSum = -1;
        for(pair<int, int> p : digitSumMap){
            if(p.second != -1){
                maxSum = max(maxSum, p.first + p.second);
            }
        }
        return maxSum;
    }
};