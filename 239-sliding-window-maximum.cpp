class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> deq;
        for (int i = 0; i < nums.size(); i++) {
            while (!deq.empty() && nums[deq.back()] <= nums[i])
                deq.pop_back();
            deq.push_back(i);
            while (!deq.empty() && deq.front() <= i - k)
                deq.pop_front();
            if (i >= k - 1)
                ans.push_back(nums[deq.front()]);
        }
        return ans;
    }
};