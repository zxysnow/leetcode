class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;
        for (int i = 4; i <= n; i++) {
            for (int k = 0; k < i; k++)
                dp[i] += dp[k] * dp[i - k - 1];
        }
        return dp[n];
    }
};
