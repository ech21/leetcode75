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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) return nullptr;
        if(root->val == val) return root;
        if (val < root->val) {return searchBST(root->left, val);}
        return searchBST(root->right, val);
    }
};

/*
Simple recursion, except that it's conditional based on the val and the root's val. 
This reduces the number of nodes visited. 

Where n = the number of nodes in the tree:
Time complexity: O(log n) at best because of a balanced binary tree, O(n) at worst
Space complexity: O(n) at worst because of the recursion stack. 
This is what happens when you do this recursively. 

For O(1) space complexity, do it iteratively like below:
*/
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* cur = root;

        while (cur) {
            if (cur->val == val) return cur;
            if (val < cur->val) cur = cur->left;
            else cur = cur->right;
        }

        return nullptr;
    }
};