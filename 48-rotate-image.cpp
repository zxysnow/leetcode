class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        for (int i = 0; i < n / 2; i++) {
            for (int k = i; k < n - i - 1; k++) {
                int tmp = matrix[i][k];
                int ti = i, tk = k;
                for (int j = 0; j < 4; j++) {
                    swap(matrix[tk][n - ti - 1], tmp);
                    swap(ti, tk);
                    tk = n - tk - 1;
                }
            }
        }
    }
};
