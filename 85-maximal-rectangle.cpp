class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        int row = matrix.size();
        if (row == 0)
            return 0;
        int col = matrix[0].size();
        vector<int> h(col, 0), l(col, 0), r(col, col);
        int ans = 0;
        for (int i = 0; i < row; i++) {
            int left = 0;
            for (int k = 0; k < col; k++) {
                if (matrix[i][k] == '1') {
                    h[k]++;
                    l[k] = max(left, l[k]);
                } else {
                    left = k + 1;
                    h[k] = l[k] = 0;
                }
            }
            int right = col;
            for (int k = col - 1; k >= 0; k--) {
                if (matrix[i][k] == '1') {
                    r[k] = min(r[k], right);
                    ans = max(ans, h[k] * (r[k] - l[k]));
                } else {
                    r[k] = col;
                    right = k;
                }
            }
        }
        return ans;
    }

};
