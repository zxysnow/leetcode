class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int t = n;
        int ans = 0;
        for (int i = 0; n != 0; i++) {
            long long k = (1ll << i);
            if ((t & k) == 0) {
                t += k;
            } else if (t - k < m) {
                ans += k;
            }
            n /= 2;
        }
        return ans;
    }
};
