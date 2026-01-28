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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        if (!root->left && !root->right) return 1;
        q.push(root);
        int result = 1, idx = 1;
        int maxSum = root->val;
        while(!q.empty()){
            int currSum = 0;
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();
                currSum += node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if (currSum > maxSum){result = idx; maxSum = currSum;}
            idx++;
        }
        return result;

    }
};

/*
Almost identical to the solution to 199, except that we keep a currentSum and compare it at the end of every level.
If it's the greatest so far, update maxSum and the index. 

Note an error you made: The for loop originally had the conditional using q.size();
However you change the size of queue in the loop by popping and pushing.
Therefore, the way to do it was to store the size in a separate variable size.

Time complexity: O(n) where n is the number of nodes of the tree. All nodes are iterated over once. 
Space complexity: O(n) in the worst case, where n is the number of nodes. This is because at worst, 
it is a binary tree, where the widest level can contain approx. half of the total nodes, or n/2.


*/