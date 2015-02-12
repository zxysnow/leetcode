class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int m = matrix.size();
        if (m == 0)
            return ;
        int n = matrix[0].size();
        bool row = false, col = false;
        for (int i = 0; i < n && !row; i++)
            if (matrix[0][i] == 0)
                row = true;
                
        for (int i = 0; i < m && !col; i++)
            if (matrix[i][0] == 0)
                col = true;
        
        for (int i = 1; i < m; i++) {
            for (int k = 1; k < n; k++)
                if (matrix[i][k] == 0) {
                    matrix[i][0] = matrix[0][k] = 0;
                }
        }
        for (int i = 1; i < m; i++) {
            for (int k = 1; k < n; k++) {
                if (matrix[i][0] == 0 || matrix[0][k] == 0)
                    matrix[i][k] = 0;
            }
        }
        
        if (row) {
            fill(matrix[0].begin(), matrix[0].end(), 0);
        }
        if (col) {
            for (int i = 0; i < m; i++)
                matrix[i][0] = 0;
        }
    }
};
