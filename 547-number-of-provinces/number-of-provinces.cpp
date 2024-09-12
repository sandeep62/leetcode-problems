class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, int i, vector<bool>& visited) {
        visited[i] = true;
        for (int u = 0; u < isConnected.size(); u++) {
            if (isConnected[i][u] == 1 && !visited[u]) {
                dfs(isConnected, u, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<bool> visited(V, false);
        int count = 0;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(isConnected, i, visited);
                count++;
            }
        }

        return count;
    }
};