// https://leetcode.com/problems/maximal-score-after-applying-k-operations/

class Solution {
public:
    
    /**
    Logic : iterate the nums array such that at every iteration look for maximum value inside the array.
    On every maximum value apply the operation. This can be achieved using maxHeap (priority_queue)
    Time Complexity - O(K*LogN + N), Space Complexity - O(N)
    where K -> number of operations
    and N -> number of elements present in the input array.
    **/
    
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> maxHeap(nums.begin(), nums.end());
        long long score = 0;
        while(maxHeap.top() != 0 && k--){
            int t = maxHeap.top();
            score += t;
            maxHeap.pop();
            // ceil(x / y) = (x + y - 1) / y
            // ceil(t / 3) = (t + 3 - 1) / 3 = (t + 2) / 3
            maxHeap.push(ceil((double)t/3));
        }
        return score;
    }
};