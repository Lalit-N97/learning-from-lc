/**
Easy - Count Items Matching a Rule
https://leetcode.com/problems/count-items-matching-a-rule/
Author : LalitN97
**/

class Solution {
public:
    
    /**
    Idea : iterate over the items array and keep a counter to increment if current item satisfies the rule.
    Time Complexity - O(N)
    Space Complexity - O(1)
    **/
    
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int count = 0;
        for(vector<string> item : items){
            if(ruleKey == "type" && ruleValue == item[0]) count++;
            if(ruleKey == "color" && ruleValue == item[1]) count++;
            if(ruleKey == "name" && ruleValue == item[2]) count++;
        }
        return count;
    }
};