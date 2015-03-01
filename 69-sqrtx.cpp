class Solution {
public:
    int sqrt(int x) {
        int l = 0, r = x;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (mid * 1ll * mid > x)
                r = mid;
            else
                l = mid + 1;
        }
        if (l * 1ll * l > x)
            l--;
        return l;
    }
};
