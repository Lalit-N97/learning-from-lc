/**
Medium - Count Nodes Equal to Average of Subtree
https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree
Written By : LalitN97
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

    /**
    Idea : use depth first search to iterate over the tree and for each node track leftSubtree's no of nodes and its sum.
    Follow the same logic for right subtree. For the current node, increase the no of nodes by 1 and the sum by current node's
    value then check if the average including current node is equal to the node's value. If it is euqal then increase the count
    Time Complexity - O(N)
    Space Complexity - O(N)
    */

    pair<int, int> getNSum(TreeNode* root, int& count){
        if(root == NULL) return make_pair(0, 0);
        pair<int, int> leftNSum = getNSum(root->left, count);
        pair<int, int> rightNSum = getNSum(root->right, count);
        int totalN = leftNSum.second + rightNSum.second + 1;
        int sumN = leftNSum.first + rightNSum.first + root->val;
        if(sumN/totalN == root->val) count++;
        return make_pair(sumN, totalN);
    }

    int averageOfSubtree(TreeNode* root) {
        int count = 0;
        getNSum(root, count);
        return count;
    }
};