class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        int ans = 0;
        int n = height.size();
        vector<int> lmin(n, -1);
        for (int i = 0; i < n; i++) {
            int id = i - 1;
            while (id != -1 && height[i] <= height[id])
                id = lmin[id];
            lmin[i] = id;
        }
        
        vector<int> rmin(n, n);
        for (int i = n - 1; i >= 0; i--) {
            int id = i + 1;
            while (id != n && height[i] <= height[id])
                id = rmin[id];
            rmin[i] = id;
            ans = max(ans, height[i] * (rmin[i] - lmin[i] - 1));
        }
        return ans;
    }
};
