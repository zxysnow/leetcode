class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> nums(n);
        int t2 = 0, t3 = 0, t5 = 0;
        nums[0] = 1;
        for (int i = 1; i < n; i++) {
            nums[i] = min(nums[t2] * 2, min(nums[t3] * 3, nums[t5] * 5));
            if (nums[i] == nums[t2] * 2)
                t2++;
            if (nums[i] == nums[t3] * 3)
                t3++;
            if (nums[i] == nums[t5] * 5)
                t5++;
        }
        return nums.back();
    }
};