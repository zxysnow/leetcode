class Solution {
public:
    int maxArea(vector<int> &height) {
        int ans = 0, l = 0, r = height.size() - 1;
        while (l < r) {
            ans = max(ans, (r - l) * min(height[r], height[l]));
            int t = r;
            if (height[r] <= height[l])
                r--;
            if (height[l] <= height[t])
                l++;
        }
        return ans;
    }
};
