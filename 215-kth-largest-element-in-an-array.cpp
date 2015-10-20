class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size() - k;
        int l = 0, r = nums.size() - 1;
        while (true) {
            int pos = partition(nums, l, r);
            if (pos == k)
                return nums[pos];
            if (pos > k) {
                r = pos - 1;
            } else {
                l = pos + 1;
            }
        }
    }

private :
    int partition(vector<int>& nums, int l, int r) {
        int p = l;
        for (int i = l; i <= r; i++) {
            if (nums[i] <= nums[r]) {
                swap(nums[i], nums[p++]);
            }
        }
        return p - 1;
    }
};
