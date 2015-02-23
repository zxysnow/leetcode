class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int pos = upper_bound(A, A + n, target) - A;
        if (pos != 0 && A[pos - 1] == target)
            return pos - 1;
        return pos;
    }
};
