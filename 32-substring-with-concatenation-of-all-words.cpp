class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        stack<int> stk;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                stk.push(i);
            } else {
                if (!stk.empty() && s[stk.top()] == '(') {
                    stk.pop();
                    if (stk.empty())
                        ans = i + 1;
                    else
                        ans = max(ans, i - stk.top());
                } else {
                    stk.push(i);
                }
            }
        }
        return ans;
    }
};
