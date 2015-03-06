class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
       vector<string> che(n, string(n, '.'));
       vector<vector<string> > ans;
       dfs(0, n, che, ans);
       return ans;
    }
    
private :
    vector<pair<int, int> > Q;
    bool place(int x, int i) {
        for (int k = 0; k < Q.size(); k++)
            if (x == Q[k].first || i == Q[k].second || abs(Q[k].first - x) == abs(Q[k].second - i))
                return false;
        return true;
    }
    void dfs(int x, int n, vector<string> &che, vector<vector<string> > &ans) {
        if (x == n) {
            ans.push_back(che);
            return ;
        }
        for (int i = 0; i < n; i++) {
            if (place(x, i)) {
                Q.push_back(make_pair(x, i));
                che[x][i] = 'Q';
                dfs(x + 1, n, che, ans);
                che[x][i] = '.';
                Q.pop_back();
            }
        }
    }
};
