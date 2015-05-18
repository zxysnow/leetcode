class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int t = 0;
        while (m != n) {
            m >>= 1;
            n >>= 1;
            t++;
        }
        return (m << t);
    }
};
