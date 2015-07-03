class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& d) {
        vector<vector<int>> dp(d.size(), vector<int>(d[0].size(), 0));
        int n = d.size();
        int m = d[0].size();
        dp[n - 1][m - 1] = max(1, 1 - d[n - 1][m - 1]);
        for (int i = n - 2; i >= 0; i--)
            dp[i][m - 1] = max(1, dp[i + 1][m - 1] - d[i][m - 1]);
        for (int k = m - 2; k >= 0; k--)
            dp[n - 1][k] = max(1, dp[n - 1][k + 1] - d[n - 1][k]);
            
        for (int i = n - 2; i >= 0; i--) {
            for (int k = m - 2; k >= 0; k--) {
                dp[i][k] = max(1, min(dp[i + 1][k], dp[i][k + 1]) - d[i][k]);
            }
        }
        
        return dp[0][0];
    }
};