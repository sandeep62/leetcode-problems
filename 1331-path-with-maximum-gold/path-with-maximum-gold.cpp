
class Solution {
public:
    // Possible directions inside the grid (up, left, right, down)
    vector<int> dx = {-1, 0, 0, 1};
    vector<int> dy = {0, -1, 1, 0};

    int dfs(int i, int j, vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // Checking for the valid grid
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) {
            return 0;
        }

        int currval = grid[i][j];
        grid[i][j] = 0; // Mark this cell as visited by setting it to 0
        int maxsum = 0;

        // Check for possible directions
        for (int d = 0; d < 4; d++) {
            int ni = i + dx[d], nj = j + dy[d];
            maxsum = max(maxsum, currval + dfs(ni, nj, grid));
        }

        grid[i][j] = currval; // Restore the cell value for other DFS calls
        return maxsum;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size(); // number of rows
        int n = grid[0].size(); // number of columns
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0) {
                    // Never visit a cell with 0 gold.
                    ans = max(ans, dfs(i, j, grid));
                }
            }
        }

        return ans;
    }
};
