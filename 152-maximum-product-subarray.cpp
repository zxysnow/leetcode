class Solution {
public:
    int maxProduct(int A[], int n) {
        int pos = 0, neg = 0;
        int ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (A[i] == 0) {
                ans = max(0, ans);
                pos = neg = 0;
            } else {
                if (pos == 0)
                    pos = A[i];
                else
                    pos *= A[i];
                if (neg == 0)
                    neg = A[i];
                else
                    neg *= A[i];
                ans = max(ans, max(pos, neg));
                int tmp = pos;
                pos = max(neg, pos);
                neg = min(tmp, neg);
                pos = (pos > 0 ? pos : 0);
                neg = (neg < 0 ? neg : 0);
            }
        }
        return ans;
    }
};
