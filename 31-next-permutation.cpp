class Solution {
public:
    void nextPermutation(vector<int> &next) {
        int pos = 0, n = next.size();
        for (int i = n - 1; i > 0; i--) {
            if (next[i - 1] < next[i]) {
                pos = lower_bound(next.begin() + i, next.end(), next[i - 1], greater<int>()) - next.begin() - 1;
                swap(next[pos], next[i - 1]);
                pos = i;
                break;
            }
        }
        reverse(next.begin() + pos, next.end());
    }
};
