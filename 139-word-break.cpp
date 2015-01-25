class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int n = s.size();
        vector<bool> dp(n, 0);
        for (int i = 0; i < n; i++) {
            if (!(i != 0 && dp[i - 1] == true || i == 0))
                continue;
            for (auto k = dict.begin(); k != dict.end(); k++) {
                int len = string(*k).size();
                if (i + len > n || dp[i + len - 1]) {
                    continue;
                }
                dp[i + len - 1] = dict.count(s.substr(i, len));
            }
        }
        return dp[n - 1];
    }
};
