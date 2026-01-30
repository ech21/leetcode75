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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if(!root) return {};
        stack<TreeNode*> st; 
        TreeNode* current = root;
        while(current || !st.empty()){
            while(current){
                st.push(current);
                current = current->left;
            }
            current = st.top();
            st.pop();
            result.push_back(current->val);;

            current = current->right;

        }
        return result;

    }
};

/*
Inorder traversal for DFS is evaluating left, node, right.

This is the GeeksForGeeks way to doing inorder travesal. basically, iterate down the left subtree first, 
then push the node's value, then start iterating down the right tree(which itself could have a left subtree).

Below was my original intuition for an inorder traversal.

Time and space complexity for both is O(n).



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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if(!root) return {};
        stack<TreeNode*> st; 
        TreeNode* current = root;
        while(current || !st.empty()){
            while(current){
                st.push(current);
                current = current->left;
            }
            current = st.top();
            st.pop();
            result.push_back(current->val);;

            current = current->right;

        }
        return result;

    }
};