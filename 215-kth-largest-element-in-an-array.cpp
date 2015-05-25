class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> t(nums.begin(), nums.end());
        return findKth(t, 0, t.size() - 1, nums.size() - k + 1);
    }

private :
    int findKth(vector<int> &nums, int l, int r, int k) {
        if (l == r)
            return nums[l];
        int t = l;
        for (int i = l; i < r; i++) {
            if (nums[i] <= nums[r]) {
                swap(nums[t++], nums[i]);
            }
        }
        swap(nums[t], nums[r]);
        if (t - l == k - 1)
            return nums[t];
        if (k <= (t - l + 1))
            return findKth(nums, l, t - 1, k);
        return findKth(nums, t + 1, r, k - (t - l + 1));
    }
};
