class Solution {
public:
    const int N = 260;
    int lengthOfLongestSubstring(string s) {
        vector<int> in(N, -1);
        vector<int> dp(s.size());
        if( s.size() == 0 )
            return 0;
        dp[0] = 1;
        in[s[0]] = 0;
        int rst = 1;
        for(int i=1; i<s.size(); i++) {
            int id = s[i];
            if( in[id] == -1 ) {
                dp[i] = dp[i-1] + 1;
            } else {
                dp[i] = min(dp[i-1] + 1, i - in[id]);
            }
            rst = max(dp[i], rst);
            in[id] = i;
        }
        return rst;
    }
};
