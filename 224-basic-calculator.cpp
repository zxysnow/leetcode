class Solution {
public:
    int calculate(string s) {
        stack<char> op;
        stack<int> num;
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (ch == ' ')
                continue;
            if (ch == '(' || ch == '+' || ch == '-') {
                op.push(s[i]);
                continue;
            }            
            if (ch == ')' && op.top() == '(')
                op.pop();
            if (isdigit(ch)) {
                int n = 0;
                while (i < s.size() && isdigit(s[i])) {
                    n = n * 10 + s[i] - '0';
                    i++;
                }
                num.push(n);
                i--;
            }
            if (!op.empty() && (op.top() == '+' || op.top() == '-')) {
                int b = num.top(); num.pop();
                int a = num.top(); num.pop();
                num.push(calcWithOp(a, b, op.top()));
                op.pop(); 
            }
        }
        return num.top();
    }
private :
    int calcWithOp(int a, int b, char op) {
        if (op == '+')
            return a + b;
        return a - b;
    }
};
