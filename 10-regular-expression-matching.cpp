class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool> > dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= n; i++) {
            dp[0][i] = (p[i - 1] == '*' && i >= 2 && dp[0][i - 2]);
        }
        for (int i = 1; i <= m; i++) {
            for (int k = 1; k <= n; k++) {
                dp[i][k] = (dp[i - 1][k - 1] && equals(s, p, i - 1, k - 1))
                    || ((dp[i - 1][k] || dp[i][k - 1]) && p[k - 1] == '*'
                        && equals(s, p, i - 1, k - 2))
                    || (p[k - 1] == '*' && k >= 2 && dp[i][k - 2]);
            }
        }
        return dp[m][n];
    }
private :
    bool equals(string &s, string &p, int i, int k) {
        return s[i] == p[k] || p[k] == '.';
    }
};
