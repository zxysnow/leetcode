class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xor_sum = 0;
        for (auto i : nums)
            xor_sum ^= i;
        int bit = xor_sum & (~(xor_sum - 1));
        int a = xor_sum;
        for (auto k : nums) {
            if (k & bit) {
                a ^= k;
            }
        }
        return vector<int>{a, a ^ xor_sum};
    }
};