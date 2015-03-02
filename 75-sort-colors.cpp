class Solution {
public:
    void sortColors(int A[], int n) {
        int l = 0, r = n - 1;
        for (int i = 0; i <= r;) {
            if (A[i] == 0)
                swap(A[i++], A[l++]);
            else if (A[i] == 2)
                swap(A[i], A[r--]);
            else
                i++;
        }
    }
};
