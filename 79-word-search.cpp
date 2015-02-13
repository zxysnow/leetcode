class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        n = board.size();
        if (n == 0)
            return false;
        m = board[0].size();
        vector<vector<bool> > used(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++)
            for (int k = 0; k < m; k++) {
                if (word[0] == board[i][k]) {
                    if (dfs(i, k, 1, word, board, used))
                        return true;
                }
            }
        return false;
    }

private:
    int dir[8] = {0, 1, 0, -1, 1, 0, -1, 0};
    int n, m;
    
    bool dfs(int x, int y, int pos, string &word, vector<vector<char> > &board, vector<vector<bool> > &used) {
        if (pos == word.size())
            return true;
        used[x][y] = true;
        for (int i = 0; i < 8; i+=2) {
            int xx = x + dir[i];
            int yy = y + dir[i + 1];
            if (xx < n && xx >= 0 && yy < m && yy >= 0 && !used[xx][yy] && 
                word[pos] == board[xx][yy] && dfs(xx, yy, pos + 1, word, board, used))
                    return true;
        }
        used[x][y] = false;
        return false;
    }
};
