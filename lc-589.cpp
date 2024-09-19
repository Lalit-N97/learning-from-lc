// https://leetcode.com/problems/n-ary-tree-preorder-traversal/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

/**
Time Complexity - O(N), Space Complexity - O(log N)
**/

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        ans.push_back(root->val);
        vector<Node*> neighbours = root->children;
        for(Node* neighbour : neighbours){
            vector<int> sub = preorder(neighbour);
            for(int ele : sub) {
                ans.push_back(ele);
            }
        }
        return ans;
    }
};