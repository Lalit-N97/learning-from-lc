// https://leetcode.com/problems/split-linked-list-in-parts/

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

/**
Logic : 
1. get the length of the linked list 
2. see if k parts >= len then fill each node in the answer vector and after filling 
all nodes in the vector starts filling NULL until there are k parts in the vector
3. for k parts < len, iterate over the list until the k parts are exhausted.
At each iteration, calculate ith partLength and push that partlength linkedlist
into the vector. Once done reduce the size of the linked list by the partLength and 
reduce the kparts by 1. and follow the step 3 until all k parts are filled into the vector

Time Complexity - O(N + K), Space Complexity - O(N) for returning answer vector, other O(1)

**/

class Solution {
public:
    
    int len(ListNode* head){
        int count = 0;
        while(head != NULL){
            count++;
            head = head->next;
        }
        return count;
    }
    
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;
        ListNode* temp;
        int n = len(head);
        cout << n << " " << k;
        if(k >= n){
            while(k && head != NULL){
                temp = head->next;
                head->next = NULL;
                ans.push_back(head);
                head = temp;
                k--;
            }
            while(k--){
                ans.push_back(head);
            }
        }
        else{
            double nF = n;
            double nK = k;
            while(nF > 0 && nK > 0){
                int partLen = ceil(nF/nK);
                ans.push_back(head);
                int t = partLen;
                while(head->next != NULL && --t){
                    head = head->next;
                }
                temp = head->next;
                head->next = NULL;
                head = temp;
                nF -= partLen;
                nK--;
            }
        }
        return ans;
    }
};