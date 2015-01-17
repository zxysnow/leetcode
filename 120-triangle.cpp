class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int n = triangle.size();
        vector<int> dp = triangle[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            for (int k = 0; k <= i; k++) {
                dp[k] = triangle[i][k] + min(dp[k], dp[k + 1]);
            }
        }
        return dp[0];
    }
};
