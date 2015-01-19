class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if (obstacleGrid.size() == 0)
            return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int> > dp(m, vector<int>(n));
        for (int i = 0, ob = 0; i < n; i++) {
            if (obstacleGrid[0][i])
                ob = 1;
            dp[0][i] = ob ^ 1;
        }
        for (int i = 0, ob = 0; i < m; i++) {
            if (obstacleGrid[i][0])
                ob = 1;
            dp[i][0] = ob ^ 1;
        }
        
        for (int i = 1; i < m; i++) {
            for (int k = 1; k < n; k++) {
                if (obstacleGrid[i][k] == 1) {
                    dp[i][k] = 0;
                } else {
                    dp[i][k] = dp[i - 1][k] + dp[i][k - 1];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};
