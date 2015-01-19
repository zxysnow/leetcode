class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> ans;
        int m = matrix.size();
        if (m == 0)
            return ans;
        int cnt = 0, n = matrix[0].size();
        while (cnt < (min(m, n) + 1) / 2) {
            for (int k = cnt; k <= n - cnt - 1; k++)
                ans.push_back(matrix[cnt][k]);

            for (int i = cnt + 1; i <= m - cnt - 1 && n - cnt - 1 >= cnt; i++)
                ans.push_back(matrix[i][n - cnt - 1]);

            for (int k = n - cnt - 2; k >= cnt && m - cnt - 1 > cnt; k--)
                ans.push_back(matrix[m - cnt - 1][k]);

            for (int i = m - cnt - 2; i > cnt && cnt < n - cnt - 1; i--)
                ans.push_back(matrix[i][cnt]);
            cnt++;
        }
        return ans;
    }
};
