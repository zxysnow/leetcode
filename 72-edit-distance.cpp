class Solution {
public:
    int minDistance(string word1, string word2) {
        word1 = '#' + word1;
        word2 = '#' + word2;
        int n = word1.size();
        int m = word2.size();
        vector<vector<int> > dp(n, vector<int>(m, 0));
        for (int i = 0; i < m; i++)
            dp[0][i] = i;
            
        for (int i = 0; i < n; i++) 
            dp[i][0] = i;
            
        for (int i = 1; i < n; i++) {
            for (int k = 1; k < m; k++) {
                if (word1[i] == word2[k])
                    dp[i][k] = dp[i - 1][k - 1];
                else
                    dp[i][k] = min(dp[i - 1][k - 1], min(dp[i - 1][k], dp[i][k - 1])) + 1;
            }
        }
        return dp[n - 1][m - 1];
    }
};
