/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*> s1, s2;
        s1.push(root1), s2.push(root2);
        while (!s1.empty() && !s2.empty()) {
            if (dfs(s1) != dfs(s2))
                return false;
        }
        return s1.empty() && s2.empty();
    }
    int dfs(stack<TreeNode*>& s) {
        while (true) {
            TreeNode* node = s.top();
            s.pop();
            if (node->right)
                s.push(node->right);
            if (node->left)
                s.push(node->left);
            if (!node->right && !node->left)
                return node->val;
        }
    }
};


/*
Makes use of two stacks to perform DFS. The DFS function "pauses" everytime it finds a leaf node,
returning its value. The main function then compares the two leaf values from the DFS. 
Remember that to be leaf similar, the leaf values need to be in the same order.
The pausing idea is the reason the stack exists outside of the DFS function:
In order for the DFS to "continue", the stack needs to be preserved between calls.

Time complexity: O(n + m), where n and m are the number of nodes in the two trees.
Space complexity: The space complexity of DFS is O(h), where h is the height of the tree.
For balanced trees, h = log(n). Therefore, the overall space complexity is O(log(n) + log(m)).
However, for unbalanced trees, h could be as large as n, meaning worse case is O(n + m).
(The problem assumes it's a balanced tree?)



*/