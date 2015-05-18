class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        vector<vector<char>> t(grid);
        for (int i = 0; i < t.size(); i++) {
            for (int k = 0; k < t[i].size(); k++) {
                if (t[i][k] == '1') {
                    dfs(i, k, t);
                    ans++;
                }
            }
        }
        return ans;
    }

private :
    int dir[8] = {0, 1, 0, -1, -1, 0, 1, 0};
    void dfs(int x, int y, vector<vector<char>>& grid) {
        grid[x][y] = '0';
        for (int i = 0; i < 8; i += 2) {
            int xx = x + dir[i];
            int yy = y + dir[i + 1];
            if (xx >= 0 && xx < grid.size() && yy >= 0 && yy < grid[xx].size() && grid[xx][yy] == '1') {
                dfs(xx, yy, grid);
            }
        }
    }
};
