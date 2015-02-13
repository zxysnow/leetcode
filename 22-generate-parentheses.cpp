class Solution {
public:
    vector<string> generateParenthesis(int n) {
        dfs("", n, 0);
        return ans;
    }
    
private:
    vector<string> ans;
    void dfs(string s, int n, int sum) {
        if (s.size() == n * 2) {
            if (sum == 0)
                ans.push_back(s);
            return ;
        }
        
        if (sum - 1 >= 0)
            dfs(s + ')', n, sum - 1);
        if (sum + 1 <= n)
            dfs(s + '(', n, sum + 1);
    }
};
