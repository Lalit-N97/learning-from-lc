/**
Medium - Find Largest Value in Each Tree Row
https://leetcode.com/problems/find-largest-value-in-each-tree-row/
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
    we can iterate the tree in Breadth First Search manner and track the maximum at each level.
    Time Complexity - O(N)
    Space Complexity - O(N)
    where N is the number of nodes in the tree
    
    OR 
    we can iterate over the tree in Depth First Search manner. Move down the tree will increase current
    level by 1.
    Time Complexity - O(N)
    Space Complexity - O(N)
    where N is the number of nodes in the tree
    
    **/
    
    vector<int> largestValues(TreeNode* root) {
//         if(root == NULL) return {};
//         queue<TreeNode*> q;
//         q.push(root);
//         q.push(NULL); // push NULL after every level - to help track the level.
//         int levelWiseMax = INT_MIN;
//         vector<int> ans;
//         while(!q.empty()){
//             TreeNode* node = q.front(); q.pop();
//             if(node == NULL){
//                 ans.push_back(levelWiseMax);
//                 levelWiseMax = INT_MIN; // reset levelWiseMax on changing the level
//                 if(q.empty()) break;
//                 q.push(NULL);
//             }
//             else{
//                 levelWiseMax = max(levelWiseMax, node->val);
//                 if(node->left != NULL) q.push(node->left);
//                 if(node->right != NULL) q.push(node->right);
//             }
            
//         }
//         return ans;
        
        // DFS approach : 
        vector<int> ans;
        dfs(root, ans);
        return ans;
        
    }
    
    void dfs(TreeNode* root, vector<int>& ans, int level = 0){
        if(root == NULL) return;
        
        // process the current node 
        if(level + 1 > ans.size()){
            ans.push_back(root->val);
        }
        else{
            ans[level] = max(ans[level], root->val);
        }
        
        // and then move left and right
        dfs(root->left, ans, level + 1);
        dfs(root->right, ans, level + 1);
    }
};