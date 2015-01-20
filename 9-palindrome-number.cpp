class Solution {
public:
    bool isPalindrome(int x) {
        int w = 0, v = x;
        if (x < 0)
            return false;
        while (x) {
            w *= 10;
            w += x % 10;
            x /= 10;
        }
        return v == w;
    }
};
