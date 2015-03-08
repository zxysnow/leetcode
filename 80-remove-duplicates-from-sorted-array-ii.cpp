class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int k = 0, i = 0;
        for (i = 0; i < n; i++) {
            if (i < n - 2 && A[i] == A[i + 1] && A[i] == A[i + 2]) {
                A[k++] = A[i];
                A[k++] = A[i];
                while (i < n - 1 && A[i] == A[i + 1]) {
                    i++;
                }
            } else {
                A[k++] = A[i];
            }
        }
        return k;
    }
};
