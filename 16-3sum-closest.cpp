class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        int ans = num[0] + num[1] + num[2], n = num.size();
        for (int i = 0; i < n; i++) {
            for (int k = i + 1, j = n - 1; k < j;) {
                int v = num[i] + num[k] + num[j];
                if (abs(v - target) < abs(ans - target))
                    ans = v;
                if (v > target) {
                    j--;
                } else {
                    k++;
                }
            }
        }
        return ans;
    }
};
