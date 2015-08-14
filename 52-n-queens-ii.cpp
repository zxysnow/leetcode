class Solution {
public:
    int totalNQueens(int n) {
        int ans = 0;
        int column = 0, ld = 0, rd = 0;
        dfs(0, column, ld, rd, ans, n);
        return ans;
    }

private :
    void dfs(int x, int column, int ld, int rd, int &ans, int n) {
        if (x == n) {
            ++ans;
            return ;
        }
        for (int i = 0; i < n; i++) {
            int id = x + i;
            int id2 = n - x - 1 + i;
            if ((column & (1 << i)) == 0 && (ld & (1 << id)) == 0 && (rd & (1 << id2)) == 0) {
                dfs(x + 1, column | (1 << i), ld | (1 << id), rd | (1 << id2), ans, n);
            }
        }
    }
};

