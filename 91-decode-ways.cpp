class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0)
            return 0;
        vector<int> dp(n, 0);
        dp[0] = 1;
        if (s[0] < '1' || s[0] > '9')
            return 0;
        for (int i = 1; i < n; i++) {
            if (s[i] != '0')
                dp[i] = dp[i - 1];
            if (s[i] == '0' && s[i - 1] > '2')
                return 0;
            if (s[i - 1] != '0' && (s[i - 1] - '0') * 10 + s[i] - '0' <= 26)
                dp[i] += (i >= 2 ? dp[i - 2] : 1);
        }
        return dp[n - 1];
    }
};
