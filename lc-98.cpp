// https://leetcode.com/problems/validate-binary-search-tree/

/**
Logic : at every node check the inorder predecessor of that node
is less than that of that node's value and inorder successor is greater than that
of the node's value
To find the inorder predecessor and successor at every node we have to iterate 
to the bottom of the tree in one path.
Time Complexity - O(N * 2 * logN) where we are iterating the height of the tree 2
times at every node
Space Complexity - O(N)
**/

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
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        // find the inorderPredecessor of root node
        TreeNode* inorderPredecessor = root->left;
        while(inorderPredecessor != NULL and inorderPredecessor->right != NULL) {
            inorderPredecessor = inorderPredecessor->right;
        }
        // find the inorderSuccessor of root node
        TreeNode* inorderSuccessor = root->right;
        while(inorderSuccessor != NULL and inorderSuccessor->left != NULL) {
            inorderSuccessor = inorderSuccessor->left;
        }
        if(inorderPredecessor != NULL and inorderPredecessor->val >= root->val) return false;
        if(inorderSuccessor != NULL and inorderSuccessor->val <= root->val) return false;
        return isValidBST(root->left) and isValidBST(root->right);
    }
};