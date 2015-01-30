class Solution {
public:
    double pow(double x, int n) {
        bool flag = n > 0;
        long long nn = abs((long long)(n));
        double p = x;
        double ans = 1;
        while(nn) {
            if (nn & 1)
                ans *= p;
            p = p * p;
            nn >>= 1;
        }
        return flag ? ans : 1 / ans;
    }
};
