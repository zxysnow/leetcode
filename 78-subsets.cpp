class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > ans;
        int x = 0;
        vector<int> v;
        sort(S.begin(), S.end());
        for (int i = 0; i <= S.size(); i++)
            dfs(x, i, S, v, ans);
        return ans;
    }

private:
    void dfs(int id, int x, vector<int> &S, vector<int> &v, vector<vector<int> > &ans) {
        if (x == 0) {
            ans.push_back(v);
            return ;
        }
        for (int i = id; i < S.size(); i++) {
            v.push_back(S[i]);
            dfs(i + 1, x - 1, S, v, ans);
            v.pop_back();
        }
    }
};
