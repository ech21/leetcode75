class Solution {
    void dfs(vector<vector<int>>& g, vector<bool>& vis, int root) {
    int n = g.size();
    stack<int> st;
    vis[root] = 1;
    st.push(root);

    while (!st.empty()) {
        int u = st.top(); st.pop();

        for (int v = 0; v < n; ++v) {
            if (!vis[v] && g[u][v]) {
                vis[v] = 1;      // mark on push
                st.push(v);
            }
        }
    }
}


public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool> visited(isConnected.size(), false);
        int count = 0;
        for (int i = 0; i < isConnected.size(); i++) {
            if (!visited[i]) {
                count++;
                dfs(isConnected, visited, i);
            }
        }
        return count;
    }
};

/*
Basic DFS traversal, except with an additional for loop because
the input is a vector of vectors. 

If the DFS ends, it's because all of the nodes within that graph (the province)
are fully iterated through. That's why we can increment our province count, then 
do DFS again on the next univisted node.

Note that it's much faster to mark visited as true when pushing onto the stack. 
This prevents further pushes to nodes that are technically unvisited but will
eventually get visited. 

Time complexity:O(n^2) in the worst case, because all nodes and their connections need to be visited.
Space complexity: O(n) is the worst case for the stack that stores nodes to visit. 

*/