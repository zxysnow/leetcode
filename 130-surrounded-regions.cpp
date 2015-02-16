class Solution {
public:
    void solve(vector<vector<char>> &board) {
        n = board.size();
        if (n == 0)
            return ;
        m = board[0].size();
        if (m == 0)
            return ;
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O')
                dfs(i, 0, board);
            if (board[i][m - 1] == 'O')
                dfs(i, m - 1, board);
        }
        for (int i = 0; i < m; i++) {
            if (board[0][i] == 'O')
                dfs(0, i, board);
            if (board[n - 1][i] == 'O')
                dfs(n - 1, i, board);  
        }
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < m; k++) {
                board[i][k] = (board[i][k] == 'O' ? 'X' : board[i][k]);
                board[i][k] = (board[i][k] == 'A' ? 'O' : board[i][k]);
            }
        }
    }

private:
    int n, m;
    vector<int> dx{0, 1, -1, 0};
    vector<int> dy{1, 0, 0, -1};
    stack<pair<int, int> > stk;
    bool dfs(int x, int y, vector<vector<char>> &board) {
        stk.push(make_pair(x, y));
        board[x][y] = 'A';
        while (!stk.empty()) {
            pair<int, int> now = stk.top();
            stk.pop();
            for (int i = 0; i < 4; i++) {
                int xx = now.first + dx[i];
                int yy = now.second + dy[i];
                if (xx >= 0 && xx < n && yy >= 0 && yy < m && board[xx][yy] == 'O') {
                    board[xx][yy] = 'A';
                    stk.push(make_pair(xx, yy));
                }
            }
        }
    }
};
