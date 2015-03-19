class Solution {
public:
    int singleNumber(int A[], int n) {
        int one = 0, two = 0, three = 0;
        for (int i = 0; i < n; i++) {
            two |= (one & A[i]);
            one ^= A[i];
            three = ~(one & two);
            two &= three;
            one &= three;
        }
        return one;
    }
};
