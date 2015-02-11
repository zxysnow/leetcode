class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > ans(n, vector<int>(n, 0));
        int i = 0, k = -1, id = 1;
        while (id <= n * n) {
            while (k + 1 < n && ans[i][k + 1] == 0) {
                ans[i][++k] = id++;
            }
            while (i + 1 < n && ans[i + 1][k] == 0) {
                ans[++i][k] = id++;
            }
            while (k - 1 >= 0 && ans[i][k - 1] == 0) {
                ans[i][--k] = id++;
            }
            while (i - 1 >= 0 && ans[i - 1][k] == 0) {
                ans[--i][k] = id++;
            }
        }
        return ans;
    }
};
