class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &s) {
        vector<vector<int> > ans(1);
        
        sort(s.begin(), s.end());
        
        int pre = s[0], dup = 1;
        for (int i = 0; i < s.size(); i++) {
            int n = ans.size();
            if (pre != s[i])
                dup = n;
            pre = s[i];
            for (int k = n - 1; k >= n - dup; k--) {
                ans.push_back(ans[k]);
                ans.back().push_back(s[i]);
            }
        }
        return ans;
    }
};
