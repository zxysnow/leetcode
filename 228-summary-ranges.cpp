class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if (nums.size() == 0)
            return ans;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int t = i;
            while (i + 1 < n && nums[i + 1] - nums[i] == 1)
                i++;
            ans.push_back(to_string(nums[t]));
            if (i != t)
                ans.back() += "->" + to_string(nums[i]);
        }
        return ans;
    }
};