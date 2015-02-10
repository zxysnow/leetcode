class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> mi;
        vector<int> ans;
        ans.push_back(0);
        for (int i = 0; i < n; i++)
            mi.push_back(1 << i);
        for (int i = 0; i < n; i++) {
            for (int k = ans.size() - 1; k >= 0; k--)
                ans.push_back(ans[k] | mi[i]);
        }
        return ans;
    }
};
