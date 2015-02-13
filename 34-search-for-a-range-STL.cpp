class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int a = lower_bound(A, A + n, target) - A;
        if (A[a] != target)
            return vector<int>{-1, -1};
        int b = upper_bound(A, A + n, target) - A - 1;
        return vector<int>{a, b};
    }
};
