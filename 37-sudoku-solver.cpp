class Solution {
public:
    
    void solveSudoku(vector<vector<char> > &board) {
        memset(used_r, 0, sizeof(used_r));
        memset(used_c, 0, sizeof(used_c));
        memset(used_9, 0, sizeof(used_9));
        for (int i = 0; i < 9; i++) {
            for (int k = 0; k < 9; k++) {
                if (board[i][k] != '.') {
                    int x = board[i][k] - '0';
                    used_r[i][x] = used_c[k][x] = used_9[i / 3 * 3 + k / 3][x] = true;
                }
            }
        }
        dfs(board);
    }

private:
    static const int MAX = 10;
    bool used_r[MAX][MAX];
    bool used_c[MAX][MAX];
    bool used_9[MAX][MAX];
    bool check(int x, int y, int k) {
        return !used_r[x][k] && !used_c[y][k] && !used_9[x / 3 * 3 + y / 3][k];
    }
    bool dfs(vector<vector<char> > &board) {
        bool flag = false;
        for (int i = 0; i < MAX - 1; i++) {
            for (int k = 0; k < MAX - 1; k++) {
                if (board[i][k] == '.') {
                    flag = true;
                    for (int id = 1; id < MAX; id++) {
                        if (check(i, k, id)) {
                            int x = i / 3 * 3 + k / 3;
                            used_r[i][id] = used_c[k][id] = used_9[x][id] = true;
                            board[i][k] = '0' + id;
                            if (dfs(board))
                                return true;
                            board[i][k] = '.';
                            used_r[i][id] = used_c[k][id] = used_9[x][id] = false;
                        }
                    }
                    if (board[i][k] == '.')
                        return false;
                }
            }
        }
        return true;
    }
};
