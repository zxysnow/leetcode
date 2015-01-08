class Solution {
public:
    vector<vector<int> > ans;
    static const int MAX = 101;
    int now[MAX];
    bool used[MAX];
    int cnt;
    void dfs(vector<int> &num, int step, int n) {
        if (step == n) {
            ans.push_back(vector<int>(now, now + n));
            return ;
        }
        for (int i=0; i<n; i++) {
            if (!used[i]) {
                used[i] = true;
                now[step] = num[i];
                dfs(num, step + 1, n);
                used[i] = false;
            }
        }
    }
    vector<vector<int> > permute(vector<int> &num) {
        memset(used, 0, sizeof(used));
        dfs(num, 0, num.size());
        return ans;
    }
};
