// https://leetcode.com/problems/water-bottles-ii/submissions/

class Solution {
public:
    
    // Logic : Greedy thinking works -> whenever you see the full Bottles try to consume it quickly, add them into the number of consumed bottles 
    // and add this one empty bottle in the emptyBottles number.
    // Time Complexity : O(N), Space Complexity - O(1); 
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int nBottlesConsumed = numBottles;
        int nFullBottles = 0;
        int nEmptyBottles = numBottles;
        while(nEmptyBottles >= numExchange){
            nEmptyBottles -= numExchange;
            nFullBottles++;
            nBottlesConsumed += nFullBottles;
            nEmptyBottles++; // once 1 full bottle is consumed empty bottle is increased by 1
            nFullBottles = 0;
            numExchange++; 
        }
        return nBottlesConsumed;
    }
};