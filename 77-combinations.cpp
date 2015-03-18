class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > ans;
        vector<int> v;
        dfs(0, n, k, v, ans);
        return ans;
    }

private :
    void dfs(int x, int n, int cnt, vector<int> &v, vector<vector<int> > &ans) {
        if (cnt == 0) {
            ans.push_back(v);
            return ;
        }
        for (int i = x; i < n; i++) {
            v.push_back(i + 1);
            dfs(i + 1, n, cnt - 1, v, ans);
            v.pop_back();
        }
    }
};
