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
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);

    }
    int dfs(TreeNode* node, int maximum){
        if(!node) return 0;
        int count = 0;
        if(node->val >= maximum) count = 1;
        maximum = max(maximum, node->val);
        count += dfs(node->left, maximum);
        count += dfs(node->right, maximum);
        return count;
    }
};
/*
Uses basic DFS, keeping track of the maximum value found in that path so far and the count
of all nodes that are >= that max. 
Key takeaway: You don't have to use the function signature that the template gives you. node->val is completely accessible, 
you can just make a new function that includes max as an input to keep track of it through recursion.

Time complexity: O(n), where n is the number of nodes in the tree.
Space complexity: O(log n) if the tree is balanced, otherwise at worst O(n). 
In any case, the space complexity is O(h), where h is the height of the tree.

*/