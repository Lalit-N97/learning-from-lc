/**
Medium - Maximum Twin Sum of a Linked List
https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list
Written By : LalitN97
**/

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

    /**
    Idea : use recursion + slow fast pointer to reach the middle point of the even length linked list
    and then from the middle point recursion will backtrace but keep a pointer which will move forward even 
    at the time recursion will backtrace.
    Time Complexity - O(N)
    Space Complexity - O(N) - inbuilt recursive stack
    where N is the size of the linked list
    **/

    void helper(ListNode* slow, ListNode* fast, ListNode* &temp, int & maxTwinSum){
        if(fast->next == NULL){
            // which means slow pointer reached the middle point of the linked list
            temp = temp->next;
            maxTwinSum = max(maxTwinSum, temp->val + slow->val);
            return;
        }
        temp = temp->next;
        helper(slow->next, fast->next->next, temp, maxTwinSum);
        temp = temp->next;
        maxTwinSum = max(maxTwinSum, temp->val + slow->val);
        return;
    }

    int pairSum(ListNode* head) {
        ListNode* temp = head;
        ListNode* slow = head;
        ListNode* fast = head->next;
        int maxTwinSum = 0;
        helper(slow, fast, temp, maxTwinSum);
        return maxTwinSum;
    }
};