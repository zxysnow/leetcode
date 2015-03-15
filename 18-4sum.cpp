class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > ans;
        sort(num.begin(), num.end());
        for (int i = 0; i < num.size(); i++) {
            for (int k = i + 1; k < num.size(); k++) {
                int x = target - num[i] - num[k];
                for (int l = k + 1, r = num.size() - 1; l < r;) {
                    if (num[l] + num[r] > x) {
                        r--;
                    } else if (num[l] + num[r] < x) {
                        l++;   
                    } else {
                        vector<int> t = {num[i], num[k], num[l], num[r]};
                        if (ans.size() == 0 || t != ans.back())
                            ans.push_back(t);
                        l++; r--;
                    }
                }
            }
        }
        sort(ans.begin(), ans.end());
        ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
        return ans;
    }
};
