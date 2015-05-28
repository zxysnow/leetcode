class Solution {
public:
    int countPrimes(int n) {
        bool flag[n];
        memset(flag, 0, sizeof(flag));
        int bound = sqrt(n);
        int cnt = n - 2 < 0 ? 0 : n - 2;
        for (int i = 2; i <= bound; i++) {
            if (flag[i])
                continue;
            for (int k = i * i; k < n; k += i) {
                if (!flag[k]) {
                    flag[k] = true;   
                    cnt--;
                }
            }
        }
        return cnt;
    }
};
