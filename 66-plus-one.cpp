class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int add = 1;
        for (int i = digits.size() - 1; i >= 0; i--) {
            digits[i] += add;
            add = digits[i] / 10;
            digits[i] %= 10;
            if (add == 0)
                break;
        }
        if (add)
            digits.insert(digits.begin(), add);
        return digits;
    }
};
