class Solution {
public:
    string longestPalindrome(string s) {
        int mx = 0, id = 0, ans = 0, pos = 0;
        string ss = "$#";
        for (int i = 0; i < s.size(); i++) {
            ss += s[i];
            ss += '#';
        }
        vector<int> dp(ss.size(), 0);
        for (int i = 1; i < ss.size(); i++) {
            if (mx > i) {
                dp[i] = min(dp[2 * id - i], mx - i);
            } else {
                dp[i] = 1;
            }
            
            while (ss[i + dp[i]] == ss[i - dp[i]])
                dp[i]++;
            if (i + dp[i] > mx) {
                mx = i + dp[i];
                id = i;
            }
            if (dp[i] > ans) {
                ans = dp[i];
                pos = i;
            }
        }
        return s.substr((pos - ans) / 2, ans - 1);
    }
};
