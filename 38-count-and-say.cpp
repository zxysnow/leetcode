class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        for (int i = 0; i < n - 1; i++)
            s = say(s);
        return s;
    }

private :
    string say(string s) {
        ostringstream oss;
        int cnt = 1, n = s.size();
        for (int i = 1; i <= n; i++) {
            if (i == n || s[i] != s[i - 1]) {
                oss << cnt << s[i - 1];
                cnt = 1;
            } else {
                ++cnt;
            }
        }
        return oss.str();
    }
};
