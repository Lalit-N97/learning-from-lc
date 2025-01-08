/**
Medium - Remove Nodes From Linked List
https://leetcode.com/problems/remove-nodes-from-linked-list/
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
    Idea : using recursion let's say func(head->next) gets you the modified linked list as per the guidelines
    you just have to return the head return by above function or the curHead ( by connecting the prevMaxHead) by
    checking the conditions between curHead and prevMaxHead
    Time Complexity - O(N)
    Space Complexity - O(N)
    where N is the size of the input linked list
    **/

    ListNode* removeNodes(ListNode* head) {
        if(head == NULL) return head;
        ListNode* maxHead = removeNodes(head->next);
        if(maxHead == NULL) return head;
        if(maxHead->val > head->val) return maxHead;
        head->next = maxHead;
        return head;
    }
};