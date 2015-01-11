class Solution {
public:
    int trap(int A[], int n) {
        if (n == 0)
            return 0;
        int lmax = A[0];
        vector<int> rmax(n);
        rmax[n - 1] = A[n - 1];
        for (int i = n - 2; i >= 0; i--)
            rmax[i] = max(rmax[i + 1], A[i]);
        int ans = 0;
        for (int i = 1; i < n - 1; i++) {
            lmax = max(lmax, A[i]);
            ans += min(lmax, rmax[i]) - A[i];
        }
        return ans;
    }
};
