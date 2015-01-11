class Solution {
public:
    const int MAX = 10;
    bool isValidSudoku(vector<vector<char> > &board) {
        bool used_r[MAX][MAX];
        bool used_c[MAX][MAX];
        bool used_9[MAX][MAX];
        memset(used_r, 0, sizeof(used_r));
        memset(used_c, 0, sizeof(used_c));
        memset(used_9, 0, sizeof(used_9));
        for (int i = 0; i < board.size(); i++) {
            for (int k = 0; k < board[i].size(); k++) {
                char ch = board[i][k];
                if (ch == '.')
                    continue;
                int id = i / 3 * 3 + k / 3;
                int n = ch - '0';
                if (!used_r[i][n] && !used_c[k][n] && !used_9[id][n]) {
                    used_r[i][n] = used_c[k][n] = used_9[id][n] = true;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};
