class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if (n == 0)
            return 0;
        int m = matrix[0].size();
        int row = 0, column = m - 1;
        while (row < n && column >= 0) {
            if (matrix[row][column] == target) {
                return true;
            }
            if (matrix[row][column] > target) {
                --column;
            } else {
                ++row;
            }
        }
        return false;
    }
};