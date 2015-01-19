class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int> > dp(m, vector<int>(n));
        for (int i = 0; i < n; i++)
            dp[0][i] = 1;
        for (int i = 0; i < m; i++)
            dp[i][0] = 1;
        
        for (int i = 1; i < m; i++) {
            for (int k = 1; k < n; k++) {
                dp[i][k] = dp[i - 1][k] + dp[i][k - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};
