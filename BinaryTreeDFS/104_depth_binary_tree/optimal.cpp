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
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int lheight = (maxDepth(root->left));
        int rheight = (maxDepth(root->right));
        return max(lheight,rheight) + 1;
        
    }
};

/*
Simple recursive solution. Every time return, we return the max depth then add 1 for the current level.

Time complexity: O(n), where n is the number of nodes in this tree. 
Space complexity: O(h), where h is the height of the tree, because of the recursion stack.

*/