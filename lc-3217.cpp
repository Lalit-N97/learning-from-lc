// https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/

/**
Logic : 
1. store the values in a hashMap or array which needs to be removed from list
2. create a dummy node and point it's next to the head of the linked list 
 (this is to avoid deletion at head scenario, which can be handled without dummy node
 but can become some more complex, more lines of code)
3. have two pointers prev and cur (prev point to dummy node and cur points to head node)
4. iterate the list using those two pointers and remove the elements of the list if the cur node is found in the hashmap
Time Complexity - O(n + 10^5), Space Complexity - O(n + m)
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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        bool isPresent[100001] = {false};
        for(int x : nums) isPresent[x] = true;
        
        // create a dummy node whose next will point to head of the linked list;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* cur = head;
        ListNode* prev = dummy;
        while(cur != NULL){
            if(isPresent[cur->val] == true){
                prev->next = cur->next;
                delete cur;
                cur = prev->next;
            }
            else{
                prev = prev->next;
                cur = cur->next;
            }
        }
        head = dummy->next;
        return head;
    }
};