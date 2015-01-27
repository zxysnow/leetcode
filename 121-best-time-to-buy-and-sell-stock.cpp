class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n == 0)
            return 0;
        int lmin = prices[0], ans = 0;
        for (int i = 1; i < n; i++) {
            ans = max(ans, prices[i] - lmin);
            lmin = min(lmin, prices[i]);
        }
        return ans;
    }
};
