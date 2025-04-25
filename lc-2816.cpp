/**
Medium - Double a Number Represented as a Linked List
https://leetcode.com/problems/double-a-number-represented-as-a-linked-list
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
Idea : we can use the idea of basic multplication when digits of one number is mulitplied with another from right to 
left manner.
Approach : we can recursively iterate over the linkedList. Once reach the end, we can fetch the carry from the end 
and while traversing back from right to left in recursion, we can multiple each number by 2 and use the carry fetched
from the previous call.
Time Complexity - O(N)
Space Complexity - O(N)
where N is the size of the input linked list.
**/

    int getCarry(ListNode*& head){
        if(head == NULL) return 0;
        int subCarry = getCarry(head->next);
        int newNum = head->val * 2 + subCarry;
        head->val = newNum % 10;
        return newNum / 10;
    }

    ListNode* doubleIt(ListNode* head) {
        int carry = getCarry(head);
        ListNode* node = new ListNode(carry);
        node->next = head;
        return carry == 0 ? head : node;
    }
};