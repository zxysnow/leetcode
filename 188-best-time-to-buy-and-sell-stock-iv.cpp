class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() < 2 || k == 0)
            return 0;
        if (k >= prices.size() / 2)
            return calculateMaxProfit(prices);
        vector<vector<int> > dp(k + 1, vector<int>{INT_MIN, 0});
        for (int i = 0; i < prices.size(); i++) {
            for (int t = 1; t <= k; t++) {
                dp[t][BUY] = max(dp[t][BUY], dp[t - 1][SELL] - prices[i]);
                dp[t][SELL] = max(dp[t][SELL], dp[t][BUY] + prices[i]);
            }
        }
        return dp[k][SELL];
    }
private :
    const int BUY = 0;
    const int SELL = 1;
    int calculateMaxProfit(vector<int> &prices) {
        int ans = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1])
                ans += prices[i] - prices[i - 1];
        }
        return ans;
    }
};