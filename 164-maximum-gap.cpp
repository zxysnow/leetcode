class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2)
            return 0;
        int max_value = INT_MIN;
        int min_value = INT_MAX;
        for (int i : nums) {
            max_value = max(max_value, i);
            min_value = min(min_value, i);
        }
        if (max_value == min_value)
            return 0;
        int bucket_size = (max_value - min_value) / nums.size() + 1;
        int bucket_len = (max_value - min_value) / bucket_size + 1;
        vector<int> min_max(2, INT_MIN);
        min_max[0] = INT_MAX;
        vector<vector<int> > bucket(bucket_len, min_max);
        for (int i : nums) {
            int ind = (i - min_value) / bucket_size;
            bucket[ind][0] = min(i, bucket[ind][0]);
            bucket[ind][1] = max(i, bucket[ind][1]);
        }
        int ans = 0, pre = 0;
        for (int i = 1; i < bucket.size(); i++) {
            if (bucket[i][0] == INT_MAX)
                continue;
            ans = max(ans, bucket[i][0] - bucket[pre][1]);
            pre = i;
        }
        return ans;
    }
};