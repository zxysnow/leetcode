class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> stk;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i].size() > 1 || isdigit(tokens[i][0])) {
                stk.push(atoi(tokens[i].c_str()));
            } else {
                int b = stk.top(); stk.pop();
                int a = stk.top(); stk.pop();
                int now = 0;
                switch(tokens[i][0]) {
                    case '+' : now = a + b; break;
                    case '-' : now = a - b; break;
                    case '*' : now = a * b; break;
                    case '/' : now = a / b; break;
                }
                stk.push(now);
            }
        }
        return stk.top();
    }
};
