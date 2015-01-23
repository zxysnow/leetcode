class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int m = grid.size();
        if (m == 0)
            return 0;
        int n = grid[0].size();
        vector<int> dp(n, 0);
        dp[0] = grid[0][0];
        
        for (int i = 1; i < n; i++)
            dp[i] = dp[i - 1] + grid[0][i];
        
        for (int i = 1; i < m; i++) {
            dp[0] = dp[0] + grid[i][0];
            for (int k = 1; k < n; k++) {
                dp[k] = min(dp[k - 1], dp[k]) + grid[i][k];
            }
        }
        return dp[n - 1];
    }
};
