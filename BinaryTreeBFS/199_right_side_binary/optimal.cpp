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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();
                if(i == size - 1) result.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return result;
    }
};

/*
Start by adding the root to the queue. Then for every level (starting at root), 
iterate for the size of the queue(which should be the number of nodes on that level).
If it's the last node on that level, add it to the result.
Each node should add its children to the queue. 

Time complexity: O(n), where n is the number of nodes, to iterate through all nodes. 
Space complexity: O(n), where n is the number of nodes, because worst case is all the nodes
are on different levels, specifically the worst being a balanced binary tree.  

*/