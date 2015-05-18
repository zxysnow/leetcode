class Solution {
public:
    bool isHappy(int n) {
        while (!st.count(n)) {
            st.insert(n);
            int t = 0;
            while (n != 0) {
                int k = n % 10;
                t += k * k;
                n /= 10;
            }
            n = t;
            if (n == 1)
                return true;
        }
        return false;
    }

private :
    unordered_set<int> st;
};
