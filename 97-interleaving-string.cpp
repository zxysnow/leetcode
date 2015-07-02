class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size())
            return false;
        if (s3.size() == 0)
            return true;
        vector<unordered_map<int, int> > dp(2);
        int op = 1;
        if (s1[0] == s3[0])
            dp[0][0] = -1;
        if (s2[0] == s3[0])
            dp[0][-1] = 0;
        for (int i = 1; i < s3.size(); i++) {
            if (dp[op ^ 1].size() == 0)
                return false;
            for (auto& it : dp[op ^ 1]) {
                int one = it.first + 1;
                int sec = it.second + 1;
                if (one < s1.size() && s1[one] == s3[i])
                    dp[op][one] = sec - 1;
                if (sec < s2.size() && s2[sec] == s3[i])
                    dp[op][one - 1] = sec;
            }
            op ^= 1;
            dp[op].clear();
        }
        return dp[op ^ 1].size() > 0;
    }
};