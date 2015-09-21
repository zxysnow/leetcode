class Solution {
public:
    int countDigitOne(int n) {
        long long cnt = 0, base = 1;
        while (n / base >= 1) {
            long long cur = n % (base * 10) / base;
            long long higher = n / (base * 10);
            long long lower = n % base;
            if (cur < 1) {
                cnt += higher * base ;
            } else if (cur == 1) {
                cnt += higher * base + lower + 1;
            } else {
                cnt += (higher + 1) * base;
            }
            base *= 10;
        }
        return cnt;
    }
};