class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > ans;
        vector<int> v;
        sort(candidates.begin(), candidates.end());
        dfs(0, target, v, candidates, ans);
        return ans;
    }

private :
    void dfs(int x, int target, vector<int> &v, vector<int> &candidates, vector<vector<int> > &ans) {
        if (target == 0) {
            ans.push_back(v);
            return ;
        }
        for (int i = x; i < candidates.size(); i++) {
            if (target < candidates[i])
                return ;
            v.push_back(candidates[i]);
            dfs(i, target - candidates[i], v, candidates, ans);
            v.pop_back();
        }
    }
};
