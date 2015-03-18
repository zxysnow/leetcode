class Solution {
public:
    int numDistinct(string S, string T) {
        if (S.size() == 0)
            return 0;
        vector<vector<int> > dp(2, vector<int>(S.size(), 0));
        dp[0][0] = (S[0] == T[0] ? 1 : 0);
        for (int i = 1; i < S.size(); i++) {
            dp[0][i] = (S[i] == T[0] ? dp[0][i - 1] + 1 : dp[0][i - 1]);
        }
        int id = 0;
        for (int i = 1; i < T.size(); i++) {
            id ^= 1;
            dp[id][i - 1] = 0;
            for (int k = i; k < S.size(); k++) {
                dp[id][k] = dp[id][k - 1] + (S[k] == T[i] ? dp[id ^ 1][k - 1] : 0);
            }
        }
        return dp[id].back();
    }
};
