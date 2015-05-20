class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> rst;
        dfs(s, 0, rst, "", 0);
        return rst;
    }

private :
    void dfs(string &s, int x, vector<string>& rst, string now, int d) {
        if (x == s.size() && d == 4) {
            rst.push_back(now);
            return ;
        }
        if (d == 3) {
            string t = s.substr(x, s.size() - x);
            if (check(t)) {
                now += t;
                rst.push_back(now);
            }
            return ;
        }
        string w;
        for (int i = x; i < x + 3 && i < s.size(); i++) {
            w += s[i];
            if (!check(w))
                return ;
            if (s.size() - i - 1 <= (4 - d) * 3 && s.size() - i - 1 >= 3 - d)
                dfs(s, i + 1, rst, now + w + '.', d + 1);
        }
    }
    bool check(string s) {
        int num;
        if (s.size() > 3 || s.size() > 1 && s[0] == '0')
            return false;
        sscanf(s.c_str(), "%d", &num);
        return num < 256;
    }
};
