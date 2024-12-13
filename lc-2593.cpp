/**
Medium - Find Score of an Array After Marking All Elements
https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements/
Written By : LalitN97
**/


class myCompare{
    public:
    bool operator()(pair<int, int> A, pair<int, int> B){
        if(A.first == B.first) return A.second > B.second;
        return A.first > B.first;
    }
};

class Solution {
public:
    
    /**
    Idea is to store elements and there index in a greater comparision heap.
    And also track the marking of indexes of elements of nums using another array or map
    iterate over the heap and simulate the process until heap is empty.
    Time Complexity - O(N*LogN)
    Space Complexity - O(N)
    where N is the size of input vector
    **/
    
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, myCompare> pq;
        bool isMark[100001];
        memset(isMark, false, sizeof isMark);
        long long score = 0;
        for(int i = 0; i < n; i++){
            pq.push(make_pair(nums[i], i));
        }
        while(!pq.empty()){
            int num = pq.top().first;
            int idx = pq.top().second;
            if(!isMark[pq.top().second]){
                if(idx - 1 >= 0){
                    isMark[idx - 1] = true;
                }
                if(idx + 1 < n) isMark[idx + 1] = true;
                isMark[idx] = true;
                score += num;
            }
            pq.pop();
        }
        return score;
    }
};