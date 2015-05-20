class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
        vector<vector<int> > dp(2, vector<int>(nums.size(), 0));
        int ans = nums[0];
        dp[0][0] = nums[0];
        dp[1][1] = nums[1];
        ans = max(ans, nums[1]);
        for (int i = 2; i < nums.size(); i++) {
            for (int k = i - 2; k >= i - 3; k--) {
                if (i != nums.size() - 1)
                    dp[0][i] = max(dp[0][k] + nums[i], dp[0][i]);
                dp[1][i] = max(dp[1][k] + nums[i], dp[1][i]);
            }
            ans = max(ans, max(dp[0][i], dp[1][i]));
        }
        return ans;
    }
};
