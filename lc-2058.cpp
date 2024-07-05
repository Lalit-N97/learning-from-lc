// https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    // Logic: maxDistance between two critical points are the farthest ones. MinDistance can be calculated by comparing two consecutive critical points while iterating over the linkedList;
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL) return {-1, -1};
        int i = 1;
        ListNode* cur = head->next;
        ListNode* prev = head;
        int firstCriticalPoint = -1;
        int curCriticalPoint = -1;
        int prevCriticalPoint = -1;
        int minDistance = INT_MAX;
        int maxDistance = INT_MIN;
        while(cur->next != NULL){
            if((cur->val > cur->next->val && cur->val > prev->val) 
               || (cur->val < cur->next->val && cur->val < prev->val)){
                if(firstCriticalPoint == -1){
                    prevCriticalPoint = i;
                    firstCriticalPoint = i;
                }
                else{
                    curCriticalPoint = i;
                    minDistance = min(minDistance, curCriticalPoint - prevCriticalPoint);
                    prevCriticalPoint = i;
                }
            }
            prev = cur;
            cur = cur->next;
            i++;
        }
        if(minDistance == INT_MAX) return {-1, -1};
        maxDistance = curCriticalPoint - firstCriticalPoint;
        return {minDistance, maxDistance};
    }
};