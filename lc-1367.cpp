// https://leetcode.com/problems/linked-list-in-binary-tree/

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
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    // Not able to reach a proper solution:
    
    // bool helper(ListNode* head, TreeNode* root, ListNode* listHead){
    //     // reached the end of both tree and linkedlist
    //     if(root == NULL && head == NULL) return true;
    //     // when linked list is traversed fully but tree is yet reamining to be traversed
    //     if(head == NULL) return true;
    //     // when reached the bottom of the tree but still linkedlist elements are remaining to be traversed
    //     if(root == NULL) return false;
    //     bool leftAns = false;
    //     bool rightAns = false;
    //     if(root->val == head->val){
    //         leftAns = helper(head->next, root->left, listHead);
    //         rightAns = helper(head->next, root->right, listHead);
    //         if(leftAns || rightAns) return true;
    //         else return helper(listHead, root->left, listHead) || helper(listHead, root->right, listHead);
    //     }
    //     if(head != listHead) return helper(listHead, root, listHead);
    //     return helper(head, root->left, listHead) || helper(head, root->right, listHead);
    // }
    
    /**
    Logic : Brute force string mathing algorithm
    Time Complexity - O(N * M), Space Complexity - O(N + M);
    where N -> no of nodes in a Tree and M -> no of nodes in the linkedList
    **/

    // check if starting from a given root node can we get the whole linked list downwards
    bool check(ListNode* head, TreeNode* root){
        if(head == NULL) return true;
        if(root == NULL) return false;
        if(head->val != root->val) return false;
        return check(head->next, root->left) || check(head->next, root->right);
    }
    
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(root == NULL) return false;
        // check if we can get the entire linked list downwards starting from head
        // if we don't get so then check if we can get the same linked list starting from root->left
        // if not, then check if we can get the same linked list starting from root->right
        return check(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};