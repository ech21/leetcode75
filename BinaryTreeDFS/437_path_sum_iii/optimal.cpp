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
    int count = 0;
    unordered_map<long long, int> mp;

    void dfs(TreeNode* root, long long currSum, int target) {
        if (!root) return;

        currSum += root->val;

        // Check if a valid path ending here exists
        if (mp.count(currSum - target)) {
            count += mp[currSum - target];
        }

        mp[currSum]++;

        dfs(root->left, currSum, target);
        dfs(root->right, currSum, target);

        // Backtrack
        mp[currSum]--;
    }

    int pathSum(TreeNode* root, int targetSum) {
        mp[0] = 1;  // base case for starting path
        dfs(root, 0, targetSum);
        return count;
    }
};

/*
Combination of DFS and a global unordered map to store a prefix Sum frequency counter.
Start by making mp[0] = 1 because of the first node, causing one such sum to be 0. 
The DFS is a normal DFS, additionally see if the val creates a path sum, and add the currentSum
to the map. Note: many paths may have their final sum matched to target at the current node, 
which is why the map is used to track how many of each remainder there is. 

Importantly, at the end of each recursive loop do mp[currSum]--, so that upstream nodes
do not see those currSums. 

It is more efficient to keep map and count as global variables, instead of recreating them for every
recursive iteration.

Time complexity: O(n) where n is the number of nodes in the tree. Each node is visited once.
Space complexity: O(h) where h is the height of the tree. The recursion stack usees O(h), and 
the map also holds at most h unique values.



*/