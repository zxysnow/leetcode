class Solution {
public:
    const int N = 260;
    int lengthOfLongestSubstring(string s) {
        vector<int> visit(N, -1);
        int cur_len = 0;
        int max_len = 0;
        for (int i = 0; i < s.size(); i++) {
            int ch = s[i];
            if (visit[ch] == -1) {
                cur_len += 1;
            } else {
                cur_len = min(cur_len + 1, i - visit[ch]);
            }
            visit[ch] = i;
            max_len = max(cur_len, max_len);
        }
        return max_len;
    }
};
