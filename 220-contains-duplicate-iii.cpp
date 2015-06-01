class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (k == 0)
            return false;
        map<int, int> mp;
        int l = 0;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (cnt == k + 1) {
                int count = --mp[nums[l]];
                if (count == 0)
                    mp.erase(nums[l]);
                cnt--;
                l++;
            }
            auto it = mp.lower_bound(nums[i] - t);
            if (it != mp.end() && abs(it->first - nums[i]) <= t)
                return true;
            it = mp.lower_bound(nums[i]);
            if (it != mp.end() && abs(it->first - nums[i]) <= t)
                return true;
            mp[nums[i]]++;
            cnt++;
        }
        return false;
    }
};
