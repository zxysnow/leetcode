class Solution {
public:
    int maxSubArray(int A[], int n) {
        int sum = 0, ans = A[0];
        for (int i = 0; i < n; i++) {
            sum += A[i];
            ans = max(sum, ans);
            sum = sum < 0 ? 0 : sum;
        }
        return ans;
    }
};
