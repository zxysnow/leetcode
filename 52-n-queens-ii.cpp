class Solution {
public:
    int totalNQueens(int n) {
       int ans = 0;
       dfs(0, n, ans);
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
    void dfs(int x, int n, int &ans) {
        if (x == n) {
            ans++;
            return ;
        }
        for (int i = 0; i < n; i++) {
            if (place(x, i)) {
                Q.push_back(make_pair(x, i));
                dfs(x + 1, n, ans);
                Q.pop_back();
            }
        }
    }
};
