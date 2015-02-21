class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        if (rowIndex < 0)
            return ans;
        for (int i = 0; i <= rowIndex; i++) {
            for (int k = ans.size() - 1; k >= 1; k--)
                ans[k] += ans[k - 1];
            ans.push_back(1);
        }
        return ans;
    }
};
