class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> ans;
        int m = matrix.size();
        if (m == 0)
            return ans;
        int cnt = 0, n = matrix[0].size();
        while (cnt < min(m, n) / 2 + min(m, n) % 2) {
            ans.push_back(matrix[cnt][cnt]);
            for (int k = cnt + 1; k < n - cnt - 1; k++)
                ans.push_back(matrix[cnt][k]);
            
            if (n - cnt - 1 != cnt)
                ans.push_back(matrix[cnt][n - cnt - 1]);
            for (int i = cnt + 1; i < m - cnt - 1; i++)
                ans.push_back(matrix[i][n - cnt - 1]);
                
            if (m - cnt - 1 != cnt && n - cnt - 1 != cnt)
                ans.push_back(matrix[m - cnt - 1][n - cnt - 1]);
            for (int k = n - cnt - 2; k > cnt && m - cnt - 1 > cnt; k--)
                ans.push_back(matrix[m - cnt - 1][k]);
                
            if (m - cnt - 1 != cnt)
                ans.push_back(matrix[m - cnt - 1][cnt]);
            for (int i = m - cnt - 2; i > cnt && cnt < n - cnt - 1; i--)
                ans.push_back(matrix[i][cnt]);
            cnt++;
        }
        return ans;
    }
};
