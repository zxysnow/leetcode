class Solution {
public:
    vector<string> letterCombinations(string digits) {
        dfs(0, digits, "");
        return ans;
    }
private:
    const vector<string> alp = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;
    
    void dfs(int x, string &digits, string s) {
        if (x == digits.size()) {
            ans.push_back(s);
            return ;
        }
        int pos = digits[x] - '0';
        for (int k = 0; k < alp[pos].size(); k++) {
            dfs(x + 1, digits, s + alp[pos][k]);
        }
    }
};
