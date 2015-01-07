class Solution {
public:
    int reverse(int x) {
        if( x == 0 )
            return 0;
        int flag = x / abs(x);
        int ans = 0;
        x = abs(x);
        while( x ) {
            if( (ans * 10) / 10 != ans )
                return 0;
            ans *= 10;
            if( (ans + (x % 10)) - (x % 10) != ans )
                return 0;
            ans += x % 10;
            x /= 10;
        }
        return ans * flag;
    }
};
