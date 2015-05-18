class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int l = 0;
        int sum = 0;
        int min_len = nums.size() + 1;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum >= s) {
                min_len = min(min_len, i - l + 1);
            }
            while (sum - nums[l] >= s) {
                sum -= nums[l];
                l++;
                min_len = min(min_len, i - l + 1);
            }
        }
        return min_len > nums.size() ? 0 : min_len;
    }
};
