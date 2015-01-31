class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > ans;
        if (numRows == 0)
            return ans;
        ans.push_back(vector<int>(1, 1));
        for (int i = 1; i < numRows; i++) {
            vector<int> tmp;
            tmp.push_back(1);
            for (int k = 1; k < i; k++) {
                tmp.push_back(ans[i - 1][k - 1] + ans[i - 1][k]);
            }
            tmp.push_back(1);
            ans.push_back(tmp);
        }
        return ans;
    }
};
