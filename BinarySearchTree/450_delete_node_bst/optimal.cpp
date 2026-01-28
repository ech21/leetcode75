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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)
            return nullptr;
        if (root->val < key) {
            root->right = deleteNode(root->right, key); //reappend subtree back to top
        } else if (root->val > key) {
            root->left = deleteNode(root->left, key); //reappend subtree back to top
        } else { 
            if (!root->left && !root->right) { //no children
                delete (root);
                return nullptr;
            }
            if (!root->left || !root->right) { //one child
                TreeNode* temp;
                if (root->left)
                    temp = root->left;
                else
                    temp = root->right;
                delete (root);
                return temp;
            } //two children
            //to keep the tree a binary search tree, we replace
            //the value with the biggest value still less than it, 
            //otherwise known as the rightmost node in the left subtree.
            TreeNode* temp = root->left;
            while (temp->right)
                temp = temp->right;
            //replace the deleted node's val with this val
            root->val = temp->val;
            //delete the value we used to replace it
            root->left = deleteNode(root->left, temp->val);
        }
        return root;
    }
};
/*
Time complexity: O(h) where h is the height of the tree, which is at best log n (balanced)
or n (skewed)
Space complexity: O(h) where h is the heigh of tree, because of the recursion stack
*/

