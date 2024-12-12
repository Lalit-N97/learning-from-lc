/**
Easy - Take Gifts From the Richest Pile
https://leetcode.com/problems/take-gifts-from-the-richest-pile/
Author : LalitN97
**/

class Solution {
public:
    
    /**
    Idea : 
    Just use the priority Queue (max heap) to adjust the elements every second into the heap
    at the end of kth seconds. Iterate over the heap and take the sum of gifts remaining in the heap
    Time Complexity - O(K*LogN)
    Space Complexity - O(N)
    where N is the size of input array
    and K is the no of input seconds
    **/
    
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<long long> pq;
        for(int gift : gifts) pq.push(gift);
        while(k--){
            int highest = pq.top(); pq.pop();
            pq.push(sqrt(highest));
        }
        
        long long nGifts = 0;
        while(!pq.empty()){
            nGifts += pq.top();
            pq.pop();
        }
        
        return nGifts;
    }
};