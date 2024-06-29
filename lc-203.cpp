// https://leetcode.com/problems/remove-linked-list-elements/

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
    ListNode* removeElements(ListNode* head, int val) {
        /* ListNode* cur = head;
        ListNode* prev = NULL;
        while(cur){
            if(cur->val == val){
                // cur is at head
                if(cur == head){
                    head = head->next;
                    delete cur;
                    cur = head;
                }
                // cur is pointing to some middle point of linked list or it may be present in the tail of the linkedlist
                else{
                    prev->next = cur->next;
                    delete cur;
                    cur = prev->next;
                }
            }
            else{
                if(cur == head){
                    prev = head;
                    cur = cur->next;
                }
                else {
                    prev = prev->next;
                    cur = cur->next;
                }
            }
        }
        return head; */
        
        if(head == NULL) return head;
        ListNode* cur = removeElements(head->next, val);
        if(head->val == val){
            head = cur;
        }
        else{
            head->next = cur;
        }
        return head;
    }
};