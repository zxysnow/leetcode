class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1 == s2)
            return true;
        if (s1.size() != s2.size())
            return false;
        int n = s1.size();
        bool dp[n + 1][n][n];
        memset(dp, false, sizeof(dp));
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                dp[1][i][k] = (s1[i] == s2[k]);
            }
        }
        
        for (int i = 2; i <= n; i++) {
            for (int k = 0; k <= n - i; k++) {
                for (int j = 0; j <= n - i; j++) {
                    for (int cut = 1; cut < i && !dp[i][k][j]; cut++) {
                        dp[i][k][j] = (dp[cut][k][j] && dp[i - cut][k + cut][j + cut] ||
                            dp[cut][k][j + i - cut] && dp[i - cut][k + cut][j]);
                    }
                }
            }
        }
        return dp[n][0][0];
    }
};
