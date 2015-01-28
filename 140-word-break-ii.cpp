class Solution {
public:
    vector<string> ans;
    string ss;
    void findPath(int id, string p, vector< vector<int> > &path, vector<int> &pre) {
        if (id < 0) {
            ans.push_back(p);
            return ;
        }
        string tmp = (p == "" ? p : ' ' + p);
        int pid = pre[id];
        for (int i = 0; i < path[pid].size(); i++) {
            findPath(id - path[pid][i], ss.substr(id - path[pid][i] + 1, path[pid][i]) + tmp, path, pre);
        }
    }
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        int n = s.size();
        ss = s;
        vector< vector<int> > path;
        vector<int> pre(n, -1);
        vector<bool> dp(n, 0);
        for (int i = 0; i < n; i++) {
            if (i != 0 && !dp[i - 1])
                continue;
            for (auto k = dict.begin(); k != dict.end(); k++) {
                int len = string(*k).size();
				bool f = (*k == s.substr(i, len));
                if (i + len <= n && f) {
                    if (pre[i + len - 1] == -1) {
                        pre[i + len - 1] = path.size();
                        vector<int> t;
                        t.push_back(len);
                        path.push_back(t);
                    } else {
                        path[pre[i + len - 1]].push_back(len);
                    }
                }
                if (i + len > n || dp[i + len - 1]) {
                    continue;
                }
                dp[i + len - 1] = f;
            }
        }
        
        if (!dp[n - 1])
            return ans;
        findPath(n - 1, "", path, pre); 
        return ans;
    }
};
