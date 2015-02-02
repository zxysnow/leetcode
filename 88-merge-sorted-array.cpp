class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int tail = m + n - 1;
        int ia = m - 1, ib = n - 1;
        while (ia >= 0 && ib >= 0) {
            if (A[ia] > B[ib]) {
                A[tail--] = A[ia--];
            } else {
                A[tail--] = B[ib--];
            }
        }
        while (ib >= 0) {
            A[tail--] = B[ib--];
        }
    }
};
