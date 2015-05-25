class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        if (n > 55)
            return ans;
        vector<int> t;
        dfs(0, 0, k, n, ans, t);
        return ans;
    }
private :
    void dfs(int x, int sum, int k, int n, vector<vector<int>> &ans, vector<int> &t) {
        if (t.size() == k && sum == n) {
            ans.push_back(t);
            return ;
        }
        if (t.size() == k || sum == n) {
            return ;
        }
        for (int i = x + 1; i <= 9; i++) {
            if (sum + i <= n) {
                t.push_back(i);
                dfs(i, sum + i, k, n, ans, t);
                t.pop_back();
            } else {
                break;
            }
        }
    }
};
