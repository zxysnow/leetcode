class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n <= 1)
            return 0;
        int profit = 0;
        int r = prices[n - 1];
        vector<int> rmax(n, 0);
        int l = prices[0];
        vector<int> lmax(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            r = prices[i] > r ? prices[i] : r;
            rmax[i] = r - prices[i];
        }
    
        for (int i = 0; i < n; i++) {
            l = prices[i] < l ? prices[i] : l;
            lmax[i] = prices[i] - l;
        }
        
        vector<int> ans(n, 0);
        for (int i = n - 2; i >= 0; i--) {
            ans[i] = max(rmax[i], ans[i + 1]);
        }
        
        for (int i = 0; i < n - 1; i++) {
            profit = max(lmax[i] + ans[i], profit);
        }
        return profit;
    }
};
