class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > ans;
        vector<string> state(n, string(n, '.'));
        int column = 0, ld = 0, rd = 0;
        dfs(0, state, column, ld, rd, ans);
        return ans;
    }

private :
    void dfs(int x, vector<string> &state, int column, int ld, int rd, vector<vector<string> > &ans) {
        if (x == state.size()) {
            ans.push_back(state);
            return ;
        }
        for (int i = 0; i < state.size(); i++) {
            int id = x + i;
            int id2 = state.size() - x - 1 + i;
            if ((column & (1 << i)) == 0 && (ld & (1 << id)) == 0 && (rd & (1 << id2)) == 0) {
                state[x][i] = 'Q';
                dfs(x + 1, state, column | (1 << i), ld | (1 << id), rd | (1 << id2), ans);
                state[x][i] = '.';
            }
        }
    }
};

