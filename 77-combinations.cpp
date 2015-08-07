class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > ans;
        if (k > n)
            return ans;
        vector<int> nums;
        dfs(1, k, n, ans, nums);
        return ans;
    }
    
private :
    void dfs(int x, int k, int n, vector<vector<int> > &ans, vector<int> &nums) {
        if (nums.size() == k) {
            ans.push_back(nums);
            return ;
        }
        for (int i = x; i <= n; i++) {
            if (nums.size() + n - i + 1 < k)
                return ;
            nums.push_back(i);
            dfs(i + 1, k, n, ans, nums);
            nums.pop_back();
        }
    }
};
