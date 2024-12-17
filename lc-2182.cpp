/**
Medium - Construct String With Repeat Limit
https://leetcode.com/problems/construct-string-with-repeat-limit/
Written By : LalitN97
**/

class Solution {
public:
    
    /**
    Idea : 
    Store the lowercaseletters frequency in a pair which ultimately stored inside the maxHeap of pairs
    Empty the priority_queue in such a way to have the ans string populated with top and second top element 
    of maxHeap. Use the topEle repeatLimit times and use the secondTop element once just after the topEle.
    Use TopElement's frequency to populate string answer by taking care of repeastLimit occurences.
    Time Complexity - O(N*logN)
    Space Complexity - O(N)
    where N is the size of input string
    **/
    
    string repeatLimitedString(string s, int repeatLimit) {
        int lowerCaseFreq[26];
        priority_queue<pair<int, int>> pq; // maxHeap
        memset(lowerCaseFreq, 0, sizeof lowerCaseFreq);
        for(char ch : s) lowerCaseFreq[ch - 'a']++;
        for(int i = 0; i < 26; i++) {
            if(lowerCaseFreq[i] > 0) pq.push({i, lowerCaseFreq[i]});
        }
        
        string ans = "";
        while(!pq.empty()){
            pair<int, int> topEle = pq.top(); pq.pop();
            int nIterations = min(topEle.second, repeatLimit);
            while(nIterations--){
                ans += ( topEle.first + 'a');
            }
            topEle.second -= min(topEle.second, repeatLimit);
            if(topEle.second > 0) {
                if(!pq.empty()) {
                    pair<int, int> secondTop = pq.top(); pq.pop();
                    ans += (secondTop.first + 'a');
                    secondTop.second--;
                    if(secondTop.second > 0) pq.push(secondTop);
                    pq.push(topEle);
                }
            }
        }
        return ans;
    }
};