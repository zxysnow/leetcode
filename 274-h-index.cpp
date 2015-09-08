class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> dp(n, 0);
        for (auto i : citations) {
            if (i == 0)
                continue;
            dp[min(i, n) - 1]++;
        }
        int sum = 0;
        for (int i = n - 1; i >= 0; i--) {
            sum += dp[i];
            if (sum >= i + 1) {
                return i + 1;
            }
        }
        return 0;
    }
};