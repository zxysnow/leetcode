class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int pos = binarySearch(matrix, target);
        if (pos - 1 < 0)
            return false;
        return binary_search(matrix[pos - 1].begin(), matrix[pos - 1].end(), target);
    }

private:
    int binarySearch(vector<vector<int> > &matrix, int target) {
        int l = 0, r = matrix.size() - 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (matrix[mid][0] <= target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return l;
    }
};
