class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int n = obstacleGrid.size();
        if (n == 0)
            return 0;
        int m = obstacleGrid[0].size();
        vector<vector<int> > dp(n, vector<int>(m, 0));
        for (int i = 0; i < m && obstacleGrid[0][i] != 1; i++) {
            dp[0][i] = 1;
        }
        for (int i = 0; i < n && obstacleGrid[i][0] != 1; i++) {
            dp[i][0] = 1;
        }
        for (int i = 1; i < n; i++) {
            for (int k = 1; k < m; k++) {
                if (obstacleGrid[i][k] == 0) {
                    dp[i][k] = dp[i - 1][k] + dp[i][k - 1];
                }
            }
        }
        return dp.back().back();
    }
};