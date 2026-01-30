class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {

        unordered_map<string, vector<pair<string, double>>> graph;
        int eqSize = equations.size();
        vector<double> result;
        // making the graph
        for (int i = 0; i < eqSize; i++) {
            vector<string> eq = equations[i];
            pair<string, double> val = {eq[1], values[i]};
            pair<string, double> reVal = {eq[0], 1 / values[i]};
            graph[eq[0]].push_back(val);
            graph[eq[1]].push_back(reVal);
        }
        int queSize = queries.size();
        for (auto q : queries) {
            result.push_back(dfs(graph, q[0], q[1]));
        }

        return result;
    }
    double dfs(unordered_map<string, vector<pair<string, double>>> &graph, const string &from,
               const string &to) {
        stack<pair<string, double>> q;
        unordered_set<string> visited;
        if(!graph.count(from) || !graph.count(to)) return -1.0;
        if(from == to) return 1.0;
        
        q.push({from, 1});
        visited.insert(from);
        while (!q.empty()) {
            auto [str, prod] = q.top();
            q.pop();
            if(str == to) return prod;
            for(auto& [child, weight] : graph[str]){
                if(visited.count(child)) continue;
                visited.insert(child);
                q.push({child, weight * prod});
            }
        }
        return -1.0;
    }
};
/*
We first needed to create a graph, which showed direction of edges and weights.
Some mere mortals split this up into a connections container and a weights container. 
I, however, put it all into one. That's why it's an unordered map where the key is a string, 
and it points to a vector array of pairs. Esentially, the key "a" points to a list of 
its connections and the weights of them. 

Then we run DFS on each query. Start at query[0], iterate unti we hit query[1].
Multiply the products along the way. 


Intuition on the graph: Say that equations/values said a/b = 2.0. 
This means that a = 2b. It also means that b = (1/2)a. 
Let's add in b/c = 3.0. b = 3c, c = (1/3)b.
Let's say we're trying to get a/c. 
First, a = xc, where x is our answer. 
We know a = 2b and b = 3c ,so a = 6c, so x = 6. a = 2(3(c)).
The DFS is iterating through the factors. 

Perhaps in more direct terms: if we have a/b = x and b/c = y, Then a/c = a/b * b/c = xy.
Think of it like in chemistry, when you did all those unit conversions. Same thing. 
That's why in the map, we'd store a -> <b, x> to show that a/b = x. 

Where n = equations.size(), m = queries.size(), k = number of variables
Time complexity: O(n) to build the graph.
One iteration of DFS is at most O(k+n). That's because a DFS in a graph is O(V+E), 
where V is the vertices (in this case, k) and E is edges (in this case, n).
You do this m times total for all queries, so that's O(m(k+n)).
Therefore, total time complexity is O(n + m(k + n)). 

Space complexity: The graph takes up k + 2n space. 
The stack takes up k space. 
The result array takes m space. 
So the space complexity is O(k + n + m).
The auxiliary space is O(k + n). 

*/