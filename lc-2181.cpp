// https://leetcode.com/problems/merge-nodes-in-between-zeros/


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
    ListNode* mergeNodes(ListNode* head) {
        // Logic : we have many such components inside the linked list which are present between two zeros. We'll solve the 1st component and rest recursion/iteration will take care.
        // 1. Thinking of recursion : mergeNodes(head) will return us such head of linkedList which has the sum of the components exluding zeros.
        // 2. We'll start implementing mergeNode operation for the 1st component, where we'll get head at zero node.
        // 3. Move the head to the next node
        // 4. get the sum of the nodes until head hits the 0 value node again.
        // 5. when head is at 0 value node, assing the sum (which we calculated as part of iteration over the component) to that 0 value node. 
        // 6. Now pass the head to the rescursion call for doing the same in next components and save the head->next as the node returned from mergeNode() function.
        // 7. do this until head is at some node whose next is NULL, return NULL from here.
        
        if(head->next == NULL) return NULL;
        head = head->next;
        int sum = 0;
        while(head->val != 0){
            sum += head->val;
            head = head->next;
        }
        head->val = sum;
        head->next = mergeNodes(head);
        return head;
    }
    
    // Time Complexity - O(N) and Space Complexity - O(N)
    
};