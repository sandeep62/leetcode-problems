#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    vector<vector<int>> adj;
    vector<bool> viz;

    bool dfs(int v, int t) {
        if (v == t)
            return 1;
        viz[v] = 1;
        for (int u : adj[v]) {
            if (!viz[u]) {
                if (dfs(u, t))
                    return 1;
            }
        }
        return 0;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {
        adj.resize(n);
        viz.assign(n, 0);
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return dfs(source, destination);
    }
};