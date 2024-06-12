class Solution {
public:
    // Using a member variable for memoization array to avoid reinitialization in recursive calls
    vector<vector<int>> dp;

    int solve(int e, int n) {
        if (n == 0 || n == 1) {
            return n;
        }
        if (e == 1) {
            return n;
        }
        if (dp[e][n] != -1) {
            return dp[e][n];
        }
        
        int mn = INT_MAX;
        for (int k = 1; k <= n; k++) {
            int temp = 1 + max(solve(e - 1, k - 1), solve(e, n - k));
            mn = min(mn, temp);
        }
        
        return dp[e][n] = mn;
    }

    int twoEggDrop(int n) {
        int e = 2;
        dp = vector<vector<int>>(e + 1, vector<int>(n + 1, -1));
        return solve(e, n);
    }
};
