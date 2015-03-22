class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > ans;
        vector<bool> used(num.size(), 0);
		vector<int> v;
        sort(num.begin(), num.end());
        dfs(v, used, num, ans);
        return ans;
    }

private :
    void dfs(vector<int> &v, vector<bool> &used, vector<int> &num, vector<vector<int> > &ans) {
        if (v.size() == num.size()) {
            ans.push_back(v);
            return ;
        }
        for (int i = 0; i < num.size(); i++) {
            if (used[i] || i != 0 && num[i] == num[i - 1] && !used[i - 1])
				continue;
            used[i] = true;
            v.push_back(num[i]);
            dfs(v, used, num, ans);
            v.pop_back();
            used[i] = false;
        }
    }
};

