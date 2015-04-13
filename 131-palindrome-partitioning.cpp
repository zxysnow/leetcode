class Solution {
public:
    vector<vector<string> > partition(string s) {
        vector<vector<string> > vec, ans;
        int len = s.size();
        for (int i = 0; i < len; i++) {
            vector<string> v;
            for (int k = i; k < len; k++) {
                string sub = s.substr(i, k - i + 1);
                if (ispalindrome(sub))
                    v.push_back(sub);
            }
            vec.push_back(v);
        }
        vector<string> v;
        dfs(0, s, vec, v, ans);
        return ans;
    }

private :
    void dfs(int x, string s, vector<vector<string> > &vec, vector<string> &v, vector<vector<string> > &ans) {
        if (x == s.size()) {
            ans.push_back(v);
            return ;
        }
        string t = "";
        for (int i = 0; i < vec[x].size(); i++) {
            v.push_back(vec[x][i]);
            dfs(x + vec[x][i].size(), s, vec, v, ans);
            v.pop_back();
        }
    }
    bool ispalindrome(string s) {
        int len = s.size();
        for (int i = 0; i < s.size() / 2; i++) {
            if (s[i] != s[len - i - 1])
                return false;
        }
        return true;
    }
};
