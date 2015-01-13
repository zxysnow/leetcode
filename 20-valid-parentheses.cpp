class Solution {
public:
    stack<char> stk;
    bool isValid(string s) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                stk.push(s[i]);
            } else {
                if (!stk.empty() && (s[i] == ')' && s[i] - 1 == stk.top() || s[i] - 2 == stk.top())) {
                    stk.pop();
                } else {
                    return false;
                }
            }
        }
        return stk.empty();
    }
};
