class Solution {
public:
    int divide(int dividend, int divisor) {
        long long a = dividend;
        long long b = divisor;
        if (b == 0)
            return INT_MAX;
        if (b == 1)
            return (int)a;
        int flag = 1;
        if (a < 0) {
            flag *= -1;
            a *= -1;
        }
        if (b < 0) {
            flag *= -1;
            b *= -1;
        }
        int ans = 0;
        while (a >= b) {
            int i = 0;
            while (((long long)(b) << i) <= a) {
                i++;
            }
            ans += (1 << (i - 1));
            a -= (b << (i - 1));
        }
        if (ans * flag * 1ll * flag < 0)
            return INT_MAX;
        return ans * flag;
    }
};
