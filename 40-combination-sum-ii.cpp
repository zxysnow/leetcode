class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int> > ans;
        vector<int> v;
        sort(num.begin(), num.end());
        dfs(0, target, v, num, ans);
        return ans;
    }

private :
    void dfs(int x, int target, vector<int> &v, vector<int> &num, vector<vector<int> > &ans) {
        if (target == 0) {
            ans.push_back(v);
            return ;
        }
        for (int i = x; i < num.size(); i++) {
            if (target < num[i])
                return ;
            if (i != x && num[i - 1] == num[i])
                continue;
            v.push_back(num[i]);
            dfs(i + 1, target - num[i], v, num, ans);
            v.pop_back();
        }
    }
};
